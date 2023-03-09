# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 11:43:16 by yoonslee          #+#    #+#              #
#    Updated: 2023/03/09 12:40:58 by yoonslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
SRCS= small_element.c 
OBJS= $(SRCS:.c=.o)

HEADER = push_swap.h
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all:$(NAME)

$(NAME):$(OBJS)
		make -C libft all
		cc $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(OBJS):$(SRCS)
		cc -c $(FLAGS) $(SRCS)

clean:
		rm -rf $(OBJS)
		make -C libft clean

fclean:clean
		rm -rf $(NAME)
		rm -rf libft/libft.a

re:fclean clean all

.PHONY:all, clean, fclean, re