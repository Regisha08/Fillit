NAME=fillit.a

# Source functions.
SRCS 		:= *.c

# Source object files.
OBJECTS		:= *.o

# Files directory.
INCLUDES 	:= libft/

all: $(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror -g fillit.c area.c convert_to_letter.c check_and_add_fig.c create_fig.c move_fig.c save_fig.c valid_fig.c $(INCLUDES)$(SRCS)

clean:
	/bin/rm -f $(INCLUDES)*.o $(INCLUDES)*.gch *.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all