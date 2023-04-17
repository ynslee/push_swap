/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:00:09 by yoonslee          #+#    #+#             */
/*   Updated: 2023/04/17 17:13:26 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	int	i;
	int	temp;

	i = 0;
	if (ps->len_a < 2)
		return ;
	temp = ps->stack_a[0];
	while (i < ps->len_a - 1)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[i] = temp;
	ps->number_amount++;
	i = 0;
	// while (i < ps->len_a)
	// {
	// 	ft_printf("now stack a[%d] is %d\n", i, ps->stack_a[i]);
	// 	i++;
	// }
	ft_printf("ra\n");
}

void	rb(t_ps *ps)
{
	int	i;
	int	temp;

	i = 0;
	if (ps->len_b < 2)
		return ;
	temp = ps->stack_b[0];
	while (i < ps->len_b - 1)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[i] = temp;
	ps->number_amount++;
	i = 0;
	ft_printf("rb\n");
}

void	rr(t_ps *ps)
{
	if (ps->len_a < 2 || ps->len_b < 2)
		return ;
	ra(ps);
	rb(ps);
	ps->number_amount++;
	ft_printf("rr\n");
}
