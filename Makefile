# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnureeva <rnureeva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 04:40:07 by aponomar          #+#    #+#              #
#    Updated: 2019/09/22 19:47:10 by rnureeva         ###   ########.fr        #
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
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(INCLUDES)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all


# NAME = fillit
# INCLUDES = -I fillit.h
# LIBFT = libft/libft.a
# CC = gcc
# RM = rm -f
# CFLAGS = -Wall -Werror -Wextra -g

# SRC =	.src/add_fig.c
# 		.src/del_fig.c
# 		.src/remove_fig.c
# 		.src/area.c
# 		.src/fillit.c
# 		.src/read_save_fig.c
# 		.src/save_fig.c

# OBJ = $(SRC:.c=.o)

# %.o:%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# all: $(NAME)
# 	$(NAME): $(OBJ)
# 	@make -C libft
# 	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) -o $(NAME)

# clean:
# 	@/bin/$(RM) $(OBJ)
# 	@make -C libft/ clean

# fclean: clean
# 	@/bin/$(RM) $(NAME)
# 	@make -C libft/ clean

# re: fclean all

# NAME = fillit
# SRC =	.src/add_fig.c
# 		.src/del_fig.c
# 		.src/remove_fig.c
# 		.src/area.c
# 		.src/fillit.c
# 		.src/read_save_fig.c
# 		.src/save_fig.c

# OBJ = $(patsubst %.c, %.o, $(SRC))

# all: $(NAME)

# $(NAME):
# 	make -C libft
# 	gcc -Werror -Wextra -Wall $(SRC) libft/libft.a -o $(NAME)

# # clean:
# # 	rm -rf $(OBJ)
# # 	make clean -C libft

# # fclean: clean
# # 	rm -rf $(NAME)
# # 	make fclean -C libft

# # re: fclean all

# clean:
# 	@make -C libft/ clean

# fclean: clean
# 	/bin/rm -f $(NAME)
# 	@make -C libft/ fclean

# re: fclean all
