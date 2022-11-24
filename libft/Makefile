# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 12:59:46 by minson            #+#    #+#              #
#    Updated: 2022/11/24 14:35:26 by minson           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_striteri.c

BONUS_SRCS = ft_lstsize.c \
			 ft_lstadd_back.c \
			 ft_lstadd_front.c \
			 ft_lstclear.c \
			 ft_lstdelone.c \
			 ft_lstiter.c \
			 ft_lstlast.c \
			 ft_lstmap.c \
			 ft_lstnew.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

%.o: %.c
		$(CC) -I $() -c $< -o $@

$(NAME): $(SRCS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)

bonus: $(NAME)
		$(CC) $(FLAGS) $(BONUS_SRCS) -o $(NAME)

clean:
		$(RM) srcs/*.o

fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY : all clean fclean re