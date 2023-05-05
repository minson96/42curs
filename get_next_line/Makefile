NAME = get_next_line.a

SRCS =	get_next_line.c get_next_line_utils.c

BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS	= $(SRCS:%.c=%.o)

BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)

FLAGS	= -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(BONUS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all	:	$(NAME)

$(NAME)	:	$(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(CC)	:
	cc

%.o	: %.c
	$(CC) $(FLAGS) -c $^ -o $@

bonus	:
	make WITH_BONUS=1 all

clean	:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY	:	all bonus clean fclean re