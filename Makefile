# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arz <arz@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 16:23:46 by cdemetra          #+#    #+#              #
#    Updated: 2020/05/13 00:40:51 by arz              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror
LIB_DIR = libft/
HEADER_DIR = includes/

LIB = -L ./libft -lft
LIBPATH = libft/

MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a

LIBX = -lmlx -lm -lft -L libft/ -L ./minilibx_macos/ -framework OpenGL -framework AppKit
LIBXL = -lm -L libft/ -lft -L/usr/lib/X11 -lmlx -lXext -lX11

#################### FDF SOURCE FILES ####################
SRC = main.c read_file.c create_matrix.c draw.c  f_free.c img_projection.c \
		init.c malloc.c some_function.c keys_hook.c color.c keys_hook_additional.c

SRC_DIR = sources/
######################################################

RED			=	\033[0;31m
YELLOW		=	\x1B[93m
GREEN		=	\033[0;32m
NC			=	\033[0m
NC1			=	\033[5m
COOL		=	\033[38;5;206;48;5;57m
ANTS		=	\033[38;05;107m
COOL2		=	\033[01;38;05;97m
LAGUNA		=	\033[01;38;05;51m
ORANGE		=	\x1B[38;5;208m
PURPLE		= 	\033[01;38;05;129m

OBJ = $(patsubst %.c,%.o,$(SRC))

OBJ_DIR = obj/

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@ -I $(HEADER_DIR)

$(NAME): $(MINILIBX) $(addprefix $(OBJ_DIR),$(OBJ))
	@make -C $(LIBPATH)
	@gcc $(FLAGS) $(addprefix $(OBJ_DIR),$(OBJ)) $(LIB) $(LIBX) -o $(NAME)
	@echo "✅  $(ANTS)FDF Created from Mac!$(NC) ✅							       $(COOL2)❒$(NC)"

$(MINILIBX):
	@make -sC $(MINILIBX_DIRECTORY)
	@echo "✅  $(PURPLE)FDF Created MinilibX!$(NC) ✅							       $(COOL2)❒$(NC)"

linux: $(addprefix $(OBJ_DIR),$(OBJ))
	@make -C $(LIBPATH)
	@gcc -no-pie $(FLAGS) $(addprefix $(OBJ_DIR),$(OBJ)) $(LIB) $(LIBXL) -o $(NAME)
	@echo "✅  $(ANTS)FDF Created from Linux!$(NC) ✅							       $(COOL2)❒$(NC)"

clean:
		@echo "$(RED)deleting object files...$(NC) ✔"
		@echo "$(RED)------------------------------$(NC)"
		@make -C $(LIBPATH) clean
		@make -C $(MINILIBX_DIRECTORY) clean
		@rm -Rf $(OBJ_DIR)

fclean: clean
		@echo "$(RED)deleting  ...$(NC) ✔"
		@echo "$(RED)---------------------------$(NC)"
		@make -C $(LIBPATH) fclean
		@rm -f $(MINILIBX)
		@rm -f $(NAME)

re: fclean all
