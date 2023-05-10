/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:41:20 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/10 16:57:28 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_element(t_ps *ps)
{
	if (ps->a[0] > ps->a[1])
		sa(ps);
	return ;
}

void	three_element(t_ps *ps)
{
	if (sorted_orderly(ps->a, ps->len_a) == 1)
		return ;
	if (ps->a[2] > ps->a[0] && ps->a[2] > ps->a[1])
	{
		sa(ps);
		return ;
	}
	if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
	{
		ra(ps);
		if (ps->a[0] > ps->a[1])
			sa(ps);
		return ;
	}
	if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2])
	{
		rra(ps);
		if (ps->a[0] > ps->a[1])
			sa(ps);
		return ;
	}
}

void	four_element(t_ps *ps)
{
	int	min;

	if (sorted_orderly(ps->a, ps->len_a) == 1)
		return ;
	min = find_min(ps);
	if (min == 1)
		sa(ps);
	if (min == 2)
	{
		ra(ps);
		ra(ps);
	}
	if (min == 3)
		rra(ps);
	pb(ps);
	three_element(ps);
	pa(ps);
	return ;
}

void	five_element(t_ps *ps)
{
	int	min;

	if (sorted_orderly(ps->a, ps->len_a) == 1)
		return ;
	min = find_min(ps);
	if (min == 1)
		sa(ps);
	if (min == 2)
	{
		ra(ps);
		ra(ps);
	}
	if (min == 3)
	{
		rra(ps);
		rra(ps);
	}
	if (min == 4)
		rra(ps);
	pb(ps);
	four_element(ps);
	pa(ps);
	return ;
}

void	small_sort(t_ps *ps)
{
	if (sorted_orderly(ps->a, ps->len_a) == 1)
		return ;
	if (ps->len_a == 2)
		two_element(ps);
	if (ps->len_a == 3)
		three_element(ps);
	if (ps->len_a == 4)
		four_element(ps);
	if (ps->len_a == 5)
		five_element(ps);
	return ;
}
