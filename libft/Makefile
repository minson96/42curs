NAME = libft

SRCS = 
SRCS_DIR = $(addprefix srcs/, $(SRCS))
OBJS_DIR = $(SRCS_DIR:.c=.o)
INCLUDES_DIR = includes

CC = gcc -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

%.o: %.c
$(CC) -I $(INCLUDES_DIR) -c $< -o $@

$(NAME): $(OBJS_DIR)
$(CC) $(OBJS_DIR) -o $(NAME)

clean:
$(RM) srcs/*.o

fclean: clean
$(RM) $(NAME)

re:		fclean all

.PHONY : all clean fclean re