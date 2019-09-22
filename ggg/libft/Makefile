# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 11:15:25 by dbubnov           #+#    #+#              #
#    Updated: 2019/09/21 17:07:30 by rnureeva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=*.c

OBJECTS=*.o

INCLUDES=./

all: $(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
