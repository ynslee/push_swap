/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:17:56 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/02 15:09:19 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps)
{
	int	temp;

	if (ps->len_a < 2)
		return ;
	temp = ps->stack_a[0];
	ps->stack_a[0] = ps->stack_a[1];
	ps->stack_a[1] = temp;
	ps->number_amount++;
	ft_putstr_fd("sa\n", 2);
}

void	sb(t_ps *ps)
{
	int	temp;

	if (ps->len_b < 2)
		return ;
	temp = ps->stack_b[0];
	ps->stack_b[0] = ps->stack_b[1];
	ps->stack_b[1] = temp;
	ps->number_amount++;
	ft_putstr_fd("sb\n", 2);
}

void	ss(t_ps *ps)
{
	if (ps->len_a < 2 || ps->len_b < 2)
		return ;
	sa(ps);
	sb(ps);
	ps->number_amount++;
	ft_putstr_fd("ss\n", 2);
}

void	ft_swap(int a, int b)
{
	int	temp;

	temp = a;
	a = b;
	b = temp;
}