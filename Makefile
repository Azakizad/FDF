# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 18:13:16 by azakizad          #+#    #+#              #
#    Updated: 2022/07/23 08:46:22 by azakizad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS=-framework OpenGL -framework AppKit
CFLAGS= -Wall -Werror -Wextra
NAME=fdf
SRC=src/*.c
INCLUDES=Libft/libft.a minilibx_macos/libmlx.a

all:
	@make -C Libft/ all
	@make -C minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(CFLAGS) -I . $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C Libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all