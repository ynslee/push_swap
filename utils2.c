/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:03 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/04 14:52:08 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*move the chunks back to stack_a*/
void	divide_to_a(t_ps *ps)
{
	int	i;
	int	length;

	i = 0;
	ps->count = 0;
	length = array[0];
	find_median_b(ps, length);
	update_array(ps);
	while (i < length)
	{
		if (ps->b[0] > ps->median)
		{
			pa(ps);
			ps->count++;
		}
		else
			ra(ps);
		i++;
	}
	ps->count = length - ps->count;
	track_chunks(ps);
	print_stacks(ps);
	if (len > 3)
		sort_to_b(ps);
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
