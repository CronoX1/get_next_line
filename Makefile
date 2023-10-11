NAME = get_next_line.a


RM = rm -f


CC = gcc


CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=100


SRCs = get_next_line.c	\
	   get_next_line_utils.c

OBJs = $(SRCs:.c=.o)


all : $(NAME)

$(NAME) : $(OBJs)
	ar rcs $(NAME) $(OBJs)

$.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJs)


fclean : clean
	$(RM) $(NAME)


re : fclean all