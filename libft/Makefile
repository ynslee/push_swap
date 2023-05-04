# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 13:37:28 by yoonslee          #+#    #+#              #
#    Updated: 2023/05/04 13:08:25 by yoonslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NaME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c\
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c\
ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c\
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_split.c ft_printf.c ft_printf_utils.c ft_printf_ptr.c ft_printf_hex.c ft_lstnew_bonus.c\
ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\
get_next_line.c get_next_line_bonus.c ft_split_one_str_out.c ft_strcmp.c

ObJS = $(SRCS:.c=.o)

HEaDER = libft.h
CC = cc
FLaGS = -Wall -Wextra -Werror

all: $(NaME)

$(NaME):$(ObJS)
		ar rcs $(NaME) $(ObJS)
		ranlib $(NaME)

$(ObJS):$(SRCS)
		${CC} -c ${FLaGS} $(SRCS) -I $(HEaDER)

clean:
		rm -rf $(ObJS)

fclean: clean
		rm -rf $(NaME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re