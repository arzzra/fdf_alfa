# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arz <arz@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 17:10:24 by arz               #+#    #+#              #
#    Updated: 2020/05/07 01:16:59 by arz              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Wextra
SRC = main.c read_file.c create_matrix.c draw.c  f_free.c img_projection.c init.c malloc.c some_function.c
OBJ = $(SRC:.c=.o)
LIBX = -lm -I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lmlx -L /libft/ -lft
LIBXL = -lm -L libft/ -lft -L/usr/lib/X11 -lmlx -lXext -lX11


all : $(NAME)

.PHONY : linux libft clean fclean re norme

$(NAME) : libft
	@echo "Creating MAC executable $(NAME) ..."
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIBX)

linux: libft
	@echo "Creating LINUX executable $(NAME) ..."
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -no-pie -o $(NAME) $(OBJ) $(LIBXL)

libft:
	@make -C libft fclean
	@make -C libft

clean :
	@echo "Removing object files ..."
	@rm -f $(OBJ)

fclean : clean
	@echo "Removing $(NAME) ..."
	@rm -f $(NAME)

re : fclean all
