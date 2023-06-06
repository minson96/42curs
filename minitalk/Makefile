NAME1 = server

NAME2 = client

SRCS1 =	server.c

SRCS2 =	client.c

OBJS1	= $(SRCS1:%.c=%.o)

OBJS2	= $(SRCS2:%.c=%.o)

FLAGS	= -Wall -Wextra -Werror

all	:	$(NAME1) $(NAME2)

$(NAME1)	:	$(OBJS1)
	$(CC) $(FLAGS) $(OBJS1) -o $(NAME1) 

$(NAME2)	:	$(OBJS2)
	$(CC) $(FLAGS) $(OBJS2) -o $(NAME2)

$(CC)	:
	cc

clean	:
	rm -f $(OBJS1) $(OBJS2) 

fclean	:	clean
	rm -f $(NAME1) $(NAME2)

re	:	fclean all

.PHONY	:	all bonus clean fclean re