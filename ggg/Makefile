# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 21:12:56 by vinograd          #+#    #+#              #
#    Updated: 2019/09/21 17:45:53 by rnureeva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRCS=src/*.c

OBJECTS=*.o

INCLUDES=libft/libft.a

FLAGS=-Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	@make -C libft/ re
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(INCLUDES) -g

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
