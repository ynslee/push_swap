/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:39:33 by yoonslee          #+#    #+#             */
/*   Updated: 2023/04/13 17:33:25 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_ps
{
	int			real_argc;
	char		**real_argv;
	t_node		*stack_a;
	t_node		*stack_b;
	int			number_amount;
}				t_ps;


int			main(int argc, char **argv);
/*find the result of real argc and real argv*/
int			get_real_argc(int argc, char **argv);
void		free_split_result(char **str_array);
int			get_real_argv(t_ps *ps, char **argv);
int			get_real_args(int argc, char **argv, t_ps *ps);


int			check_real_argv(t_ps *ps);

/*error management*/
void		ft_error(void);

#endif
