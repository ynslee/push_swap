/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:41:20 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/02 12:49:46 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_element(t_ps *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1])
		sa(ps);
	return ;
}

void	three_element(t_ps *ps)
{
	if (ps->stack_a[0] < ps->stack_a[2] && ps->stack_a[2] < ps->stack_a[1])
	{
		sa(ps);
		ra(ps);
		return ;
	}
	if (ps->stack_a[1] < ps->stack_a[0] && ps->stack_a[0] < ps->stack_a[2])
	{
		sa(ps);
		return ;
	}
	if (ps->stack_a[2] < ps->stack_a[0] && ps->stack_a[0] < ps->stack_a[1])
	{
		rra(ps);
		return ;
	}
	if (ps->stack_a[1] < ps->stack_a[2] && ps->stack_a[2] < ps->stack_a[0])
	{
		ra(ps);
		return ;
	}
	if (ps->stack_a[2] < ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[0])
		three_element_extra(ps);
	return ;
}

void	three_element_extra(t_ps *ps)
{
	if (ps->stack_a[2] < ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[0])
	{
		sa(ps);
		rra(ps);
		return ;
	}
}

void	four_element(t_ps *ps)
{
	int	min;

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

void	small_sort(t_ps *ps)
{
	if (ps->real_argc == 2)
		two_element(ps);
	if (ps->real_argc == 3)
		three_element(ps);
	if (ps->real_argc == 4)
		four_element(ps);
	if (ps->real_argc == 5)
		five_element(ps);
	return ;
}
