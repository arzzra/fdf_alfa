# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arz <arz@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 16:23:46 by cdemetra          #+#    #+#              #
#    Updated: 2020/05/13 00:46:28 by arz              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HDRS = $(LIBFT_DIR)includes/

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = ./minilibx_macos/
MLX_HDRS = $(MLX_DIR)

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
MLX_FLAGS = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCS = -I$(HDRS_DIR) -I$(LIBFT_HDRS) -I$(MLX_HDRS)


SRC_DIR = ./src/

SRC          = main.c \
               read_file.c \
               create_matrix.c \
               draw.c \
               f_free.c \
               img_projection.c \
               init.c \
               malloc.c \
               some_function.c \
               keys_hook.c \
               color.c \
               keys_hook_additional.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = objects/
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJECTS	= $(addprefix $(OBJ_DIR), $(OBJ))

HDR      =  fdf.h\
	           controls_keys.h

HDRS_DIR = ./includes/
HDRS = $(addprefix $(HDRS_DIR), $(HDR))

GREEN = \033[0;32m
RED = \033[0;31m
CLEAR = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJECTS)
	@$(CC) $(FLAGS) $(MLX_FLAGS) $(INCS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)objects file created...$(CLEAR) ✔"
	@echo "$(GREEN)program fdf created...$(CLEAR) ✔"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)objects/ created...$(CLEAR) ✔"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HDRS)
	@$(CC) $(FLAGS) -c $(INCS) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	@echo "$(GREEN)libmlx.a created...$(CLEAR) ✔"
	@$(MAKE) -sC $(MLX_DIR)

clean:
	@echo "$(RED)deleting object files...$(CLEAR)"
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@echo "$(RED)deleting minilibx object files...$(CLEAR) ✔"
	@$(MAKE) -sC $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)all object files deleted$(CLEAR) ✔"

fclean: clean
	@echo "$(RED)deleting static library files...$(CLEAR)"
	@echo "$(RED)deleting libmlx.a file...$(CLEAR) ✔"
	@rm -f $(MLX)
	@echo "$(RED)deleting libft.a file...$(CLEAR) ✔"
	@rm -f $(LIBFT)
	@echo "$(RED)all static library files deleted$(CLEAR) ✔"
	@echo "$(RED)deleting fdf program...$(CLEAR)"
	@rm -f $(NAME)
	@echo "$(RED)program fdf deleted$(CLEAR) ✔"

re:
	@$(MAKE) fclean
	@$(MAKE) all