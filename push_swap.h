/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:39:33 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/02 15:09:24 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

// typedef struct s_node{
// 	int				value;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// }			t_node;

typedef struct s_ps
{
	int		real_argc;
	char	**real_argv;
	int		*array;
	int		*stack_a;
	int		*stack_b;
	int		len;
	int		len_a;
	int		len_b;
	int		number_amount;
	int		medium;
}			t_ps;


int			main(int argc, char **argv);

/*find the result of real argc and real argv - get_real_args.c*/
int			get_real_argc(int argc, char **argv);
void		free_split_result(char **str_array);
int			get_real_argv(t_ps *ps, char **argv);
int			get_real_args(int argc, char **argv, t_ps *ps);

/*Check if args are number and not duplicates - check_argv.c*/
int			check_real_argv(t_ps *ps);
void		arg_is_number(int i, int j, t_ps *ps);
int			ft_strlen_ps(char *str);

/*Initiate stack*/
int			init_stack(t_ps	*ps);

/*error management*/
void		ft_error(void);
void		msg_error(char *msg, int error_code);

/*check if arg is sorted*/
int			sorted_orderly(int *array, int len);
int			sorted_reverse(int *array, int len);

/*small element*/
void		small_sort(t_ps *ps);
void		two_element(t_ps *ps);
void		three_element(t_ps *ps);
void		three_element_extra(t_ps *ps);
void		four_element(t_ps *ps);
void		five_element(t_ps *ps);

/*utilities for sorting algorithm*/
void		sort_init(t_ps *ps);
void		sort_algo(t_ps *ps);
int			find_min(t_ps *ps);
int			find_medium(t_ps *ps, int i);
void		ft_swap(int a, int b);

/*allowed functions only*/
void		sa(t_ps *ps);
void		sb(t_ps *ps);
void		ss(t_ps *ps);
void		pa(t_ps *ps);
void		pb(t_ps *ps);
void		ra(t_ps *ps);
void		rb(t_ps *ps);
void		rr(t_ps *ps);
void		rra(t_ps *ps);
void		rrb(t_ps *ps);
void		rrr(t_ps *ps);

#endif
