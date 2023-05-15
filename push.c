/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:29:45 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/12 13:48:27 by yoonslee         ###   ########.fr       */
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
	temp = ps->b[0];
	while (i < ps->len_a)
	{
		ps->a[ps->len_a - i] = ps->a[ps->len_a - (i + 1)];
		i++;
	}
	ps->a[0] = temp;
	i = 0;
	while (i < ps->len_b - 1)
	{
		ps->b[i] = ps->b[i + 1];
		i++;
	}
	ps->len_a++;
	ps->len_b--;
	ps->number_amount++;
	ft_printf("pa\n");
}

void	pb(t_ps *ps)
{
	int	i;
	int	temp;

	i = 0;
	if (ps->len_a == 0)
		return ;
	temp = ps->a[0];
	while (i < ps->len_b)
	{
		ps->b[ps->len_b - i] = ps->b[ps->len_b - (i + 1)];
		i++;
	}
	ps->b[0] = temp;
	i = 0;
	while (i < ps->len_a - 1)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->len_a--;
	ps->len_b++;
	ps->number_amount++;
	ft_printf("pb\n", 2);
}
