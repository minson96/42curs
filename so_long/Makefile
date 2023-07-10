NAME = so_long

CC = cc

LIB = libso_long.a

LIBNAME = so_long

SUBLIB = libftprintf.a

SUBLIBNAME = ftprintf

AR = ar

AFLAGS = -rcs

CFLAGS1 = -Wall -Wextra -Werror   -L./mlx -lmlx -framework OpenGL -framework AppKit
CFLAGS2 = -Wall -Wextra -Werror

SRCS = so_long.c \
	./libft/ft_substr.c \
	./libft/ft_split.c \
	./libft/ft_strjoin.c \
	./libft/ft_strlcpy.c \
	./libft/ft_strdup.c \
	./libft/ft_strlen.c \
	./libft/ft_strlcat.c \
	./srcs/so_long_utils.c \
	./srcs/get_next_line.c \
	./srcs/dfs.c \
	./srcs/error_and_free.c \
	./srcs/valid_map.c \
	./srcs/print_image.c \
	./srcs/player_move.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS2) -c -o $@ $^ -I./ 

$(LIB) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(NAME) : $(LIB)
	make -C ./mlx all
	make -C ./ft_printf all
	cp ./mlx/libmlx.a .
	$(CC) $(CFLAGS1) -l$(SUBLIBNAME) -L./ft_printf -l$(LIBNAME) -L. -o $@

clean :
	make -C ./mlx clean
	make -C ./ft_printf clean
	rm -rf $(OBJS) libmlx.a

fclean : clean
	make -C ./mlx clean
	make -C ./ft_printf fclean
	rm -rf $(LIB) $(NAME) libmlx.a

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re