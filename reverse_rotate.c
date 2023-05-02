/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:14:14 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/02 09:52:20 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps *ps)
{
	int	i;
	int	temp;

	i = ps->len_a - 1;
	if (ps->len_a < 2)
		return ;
	temp = ps->stack_a[ps->len_a - 1];
	while (0 < i)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = temp;
	ps->number_amount++;
	// i = 0;
	// while (i < ps->len_a)
	// {
	// 	ft_printf("now stack a[%d] is %d\n", i, ps->stack_a[i]);
	// 	i++;
	// }
	ft_putstr_fd("rra\n", 2);
}

void	rrb(t_ps *ps)
{
	int	i;
	int	temp;

	i = ps->len_b - 1;
	if (ps->len_b < 2)
		return ;
	temp = ps->stack_b[ps->len_b - 1];
	while (0 < i)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = temp;
	ps->number_amount++;
	ft_putstr_fd("rrb\n", 2);
}

void	rrr(t_ps *ps)
{
	if (ps->len_a < 2 || ps->len_b < 2)
		return ;
	rra(ps);
	rrb(ps);
	ps->number_amount++;
	ft_putstr_fd("rrr\n", 2);
}
