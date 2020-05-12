# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arz <arz@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 17:10:24 by arz               #+#    #+#              #
#    Updated: 2020/05/08 01:44:19 by arz              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= main.c \
          read_file.c \
          create_matrix.c \
          draw.c \
          f_free.c \
          img_projection.c \
          init.c \
          malloc.c \
          some_function.c \
          keys_hook.c \
          color.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

MINILIBX		= ./minilibx_macos/
MINILIBX_LIB	= $(addprefix $(MINILIBX),mlx.a)
MINILIBX_INC	= -I ./miniLibX
MINILIBX_LIBX	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit
MINILIBX_LIBXL = -lm -L libft/ -lft -L/usr/lib/X11 -lmlx -lXext -lX11

# ft library
LIBFT		= ./libft/
LIBFT_LIB	= $(addprefix $(LIBFT),libft.a)
LIBFT_INC	= -I ./libft
LIBFT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(LIBFT_LIB) $(MINILIBX_LIB) $(NAME)


obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MINILIBX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(LIBFT_LIB):
	make -C $(LIBFT)

$(MINILIBX_LIB):
	make -C $(MINILIBX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MINILIBX_LIBX) $(LIBFT_LNK) -lm -o $(NAME)

# linux: obj $(LIBFT_LIB) $(MINILIBX_LIB)
#     $(CC) $(OBJ) $(MINILIBX_LIBXL) $(LIBFT_LNK)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFT) clean
	make -C $(MINILIBX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
