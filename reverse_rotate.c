/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonseonlee <yoonseonlee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:14:14 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/11 16:08:01 by yoonseonlee      ###   ########.fr       */
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
	temp = ps->a[ps->len_a - 1];
	while (0 < i)
	{
		ps->a[i] = ps->a[i - 1];
		i--;
	}
	ps->a[0] = temp;
	ps->number_amount++;
	// i = 0;
	// while (i < ps->len_a)
	// {
	// 	ft_printf("now stack a[%d] is %d\n", i, ps->a[i]);
	// 	i++;
	// }
	ft_printf("rra\n");
}

void	rrb(t_ps *ps)
{
	int	i;
	int	temp;

	i = ps->len_b - 1;
	if (ps->len_b < 2)
		return ;
	temp = ps->b[ps->len_b - 1];
	while (0 < i)
	{
		ps->b[i] = ps->b[i - 1];
		i--;
	}
	ps->b[0] = temp;
	ps->number_amount++;
	ft_printf("rrb\n");
}

void	rrr(t_ps *ps)
{
	if (ps->len_a < 2 || ps->len_b < 2)
		return ;
	rra(ps);
	rrb(ps);
	ps->number_amount++;
	ft_printf("rrr\n");
}
