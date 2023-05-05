/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:03 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/05 14:43:03 by yoonslee         ###   ########.fr       */
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
	track_chunks(ps);
	print_stacks(ps);
	if (ps->count > 3)
		divide_to_a(ps, ps->count);
	divide_to_b(ps, a_before - ps->len_a);
}

void	divide_to_b(t_ps *ps, int length)
{
	int	i;
	int	count;
	int	b_before;

	i = -1;
	b_before = ps->len_b;
	if (is_sorted(ps->a, ps->len_a) == 1)
		return ;
	if (length <= 3)
		return (top_sort_a(ps, length));
	find_median(ps->a);
	while (++i < length)
	{
	// 	if (ps->a[0] < ps->median)
	// 		pb(ps);
	// 	else if (ps->a[0] == ps->median && length % 2 == 0)
	// 		pb(ps);
	// 	else if (ps->a[0] >= ps->median && ++i)
	// 		ra(ps);
	// }
	// while (i-- > 0)
	// 	rra(ps);
	// if (ps->len_b - b_before > 0 && ++ps->lvl)
	// 	add_one_num_front(ps, ps->len_b - b_init_size);
	// divide_to_b(ps, ps->len - b_before- ps->len_a + count % 2);
	}

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

void	find_median_b(t_ps *ps, int len)
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
		count = 0;
		while (j < len)
		{
			if (ps->b[i] < ps->b[j])
				count++;
			j++;
		}
		if (half == count)
			ps->median = ps->b[i];
		i++;
	}
}
