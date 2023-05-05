/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:03 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/05 11:50:55 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*move the chunks back to stack_a*/
void	divide_to_a(t_ps *ps, int length)
{
	int	i;
	int	count;

	i = -1;
	ps->count = 0;
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
	divide_to_b(ps, length - ps->count);
}

void	divide_to_b(t_ps *ps, int length)
{
	int	i;
	int	median;
	int	b_init_size;

	i = -1;
	b_init_size = ps->len_b;
	if (is_sorted(ps->a, ps->len_a) == 1)
		return ;
	if (range <= 3)
		return (sort_top_a(ps, range));
	median = find_median(ps->a, range);
	while (ps->len_b - b_init_size < range / 2)
	{
		if (ps->a[0] < median)
			pb(ps);
		else if (ps->a[0] == median && range % 2 == 0)
			pb(ps);
		else if (ps->a[0] >= median && ++i)
			ra(ps);
	}
	while (i-- > 0)
		rra(ps);
	if (ps->len_b - b_init_size > 0 && ++ps->lvl)
		add_one_num_front(ps, ps->len_b - b_init_size);
	divide_a_to_b(ps, ps->len - b_init_size - ps->len_a + range % 2);
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
