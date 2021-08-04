# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iha <iha@student.42.kr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 18:01:58 by iha               #+#    #+#              #
#    Updated: 2021/08/04 18:02:01 by iha              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES =	convert_itoh \
		convert_uitoa \
		format_char \
		format_hex \
		format_nbr \
		ft_printf \

LIB_FILES = ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memccpy \
			ft_memmove \
			ft_memchr \
			ft_memcmp \
			ft_strlen \
			ft_strlcpy \
			ft_strlcat \
			ft_strchr \
			ft_strrchr \
			ft_strnstr \
			ft_strncmp \
			ft_atoi \
			ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_toupper \
			ft_tolower \
			ft_calloc \
			ft_strdup \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_itoa \
			ft_strmapi \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_lstnew \
			ft_lstadd_front \
  			ft_lstsize \
  			ft_lstlast \
  			ft_lstadd_back \
  			ft_lstdelone \
  			ft_lstclear \
  			ft_lstiter \
  			ft_lstmap \

SRCS_DIR = ./
LIB_SRCS_DIR = ./libft/
SRCS =	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES))) \
		$(addprefix $(LIB_SRCS_DIR), $(addsuffix .c, $(LIB_FILES)))

OBJS_DIR = ./
LIB_OBJS_DIR = ./libft/
OBJS =	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES))) \
		$(addprefix $(LIB_OBJS_DIR), $(addsuffix .o, $(LIB_FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
