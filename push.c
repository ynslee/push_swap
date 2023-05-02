/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:29:45 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/02 09:52:38 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps)
{
	int	i;
	int	temp;

	i = 0;
	if (ps->len_b == 0)
		return ;
	temp = ps->stack_b[0];
	while (i < ps->len_a)
	{
		ps->stack_a[ps->len_a - i] = ps->stack_a[ps->len_a - (i + 1)];
		i++;
	}
	ps->stack_a[0] = temp;
	i = 0;
	while (i < ps->len_b - 1)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->len_a++;
	ps->len_b--;
	ps->number_amount++;
	ft_putstr_fd("pa\n", 2);
}

void	pb(t_ps *ps)
{
	int	i;
	int	temp;

	i = 0;
	if (ps->len_a == 0)
		return ;
	temp = ps->stack_a[0];
	while (i < ps->len_b)
	{
		ps->stack_b[ps->len_b - i] = ps->stack_b[ps->len_b - (i + 1)];
		i++;
	}
	ps->stack_b[0] = temp;
	i = 0;
	while (i < ps->len_a - 1)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->len_a--;
	ps->len_b++;
	ps->number_amount++;
	ft_putstr_fd("pb\n", 2);
}
