/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:03 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/09 14:40:28 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*move the chunks back to stack_a*/
void	divide_to_a(t_ps *ps, int length)
{
	int	i;
	int	count;
	int	a_before;

	i = -1;
	ps->count = 0;
	a_before = ps->len_a;
	find_median_b(ps, length);
	ft_printf("median_b is %d\n", ps->median);
	update_array(ps);
	while (++i < length)
	{
		if (ps->b[0] > ps->median)
			pa(ps);
		else if (ps->count++)
			rb(ps);
	}
	count = ps->count;
	while (count-- > 0)
		rrb(ps);
	if (ps->count <= 3)
		top_sort_b(ps);
	track_chunks(ps);
	if (ps->count > 3)
		divide_to_a(ps, ps->count);
	divide_to_b(ps, a_before - ps->len_a, i);
}

/*move the chunks back to stack_b after moving it to stack_a*/
void	divide_to_b(t_ps *ps, int length, int i)
{
	int	a_leftover;

	i = 0;
	ps->count = 0;
	a_leftover = length;
	if (sorted_orderly(ps->a, ps->len_a) == 1)
		return ;
	if (length <= 3)
	{
		top_sort_a(ps, length);
		return ;
	}
	find_median_a(ps, a_leftover);
	divide_to_b2(ps, i, a_leftover);
}

void	divide_to_b2(t_ps *ps, int i, int leftover)
{
	int	length;

	length = leftover;
	while (length-- > 0)
	{
		if (ps->a[0] <= ps->median)
		{
			pb(ps);
			ps->count++;
		}
		else
		{
			ra(ps);
			i++;
		}
	}
	while (i-- > 0)
		rra(ps);
	track_chunks(ps);
	if ((leftover - ps->count) > 3)
		divide_to_b(ps, leftover - ps->count, i);
}

/*sort top 2 or 3 of the stack_a*/
void	top_sort_a(t_ps *ps, int length)
{
	if (length == 2)
		sa(ps);
	if (length == 3 && ps->a[0] < ps->a[1] && ps->a[0] < ps->a[2])
	{	
		pb(ps);
		sa(ps);
	}
	if (ps->count == 3 && ps->b[2] < ps->b[1] && ps->b[2] < ps->b[0])
	{
		sa(ps);
		pb(ps);
		if (ps->a[0] > ps->a[1])
			sa(ps);
	}
	if (ps->count == 3 && ps->b[1] > ps->b[0] && ps->b[1] > ps->b[2])
	{
		if (ps->a[0] > ps->a[1])
			sa(ps);
		ra(ps);
		sa(ps);
		pb(ps);
		rra(ps);
	}
	pa(ps);
}

void	find_median_a(t_ps *ps, int len)
{
	int	half;
	int	i;
	int	j;
	int	count;

	if (len <= 3)
		exit(0);
	half = len / 2;
	i = 0;
	while (i < len)
	{
		j = 0;
		count = 1;
		while (j < len)
		{
			if (ps->a[i] < ps->a[j])
				count++;
			j++;
		}
		if (half == count)
			ps->median = ps->a[i];
		i++;
	}
}
