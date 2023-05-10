# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 11:43:16 by yoonslee          #+#    #+#              #
#    Updated: 2023/05/10 15:12:46 by yoonslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
SRCS= push_swap.c get_real_args.c error.c check_argv.c stack_init.c\
		rotate.c push.c reverse_rotate.c swap.c small_sort.c is_sorted.c utils.c\
		sort_algo.c sort_algo_continue.c utils2.c array.c
OBJS= $(SRCS:.c=.o)

HEADER = push_swap.h
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all:$(NAME)

$(NAME):$(OBJS)
		make -C libft all
		cc $(OBJS) -o $(NAME) libft/libft.a

$(OBJS):$(SRCS)
		cc -c $(SRCS) -I $(HEADER)

clean:
		rm -rf $(OBJS)
		make -C libft clean

fclean:clean
		rm -rf $(NAME)
		rm -rf libft/libft.a

re:fclean clean all

.PHONY:all, clean, fclean, re