/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:08 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/05 15:20:35 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check if stack A is sorted already. If not, continue to sort*/
void	sort_init(t_ps *ps)
{
	if (sorted_orderly(ps->a, ps->len_a) == 1)
		exit(0);
	if (ps->len_a <= 5)
		small_sort(ps);
	// if (sorted_reverse(ps->a, ps->len_a) == 1)
	// 	// sort_reversesort(ps);
	else
		sort_to_b(ps);
	return ;
}

/*find the median and push it to stack b*/
void	sort_to_b(t_ps *ps)
{
	int	i;
	int	length;

	i = 0;
	ps->count = 0;
	find_median(ps);
	length = ps->len_a;
	while (i < length)
	{
		if (ps->a[0] <= ps->median)
		{
			pb(ps);
			ps->count++;
		}
		else
			check_rotate(ps);
		i++;
	}
	track_chunks(ps);
	print_stacks(ps);
	if (ps->len_a > 3)
		sort_to_b(ps);
	if (ps->array[0] == 0)
		return ;
	sort_continue(ps);
}

void	find_median(t_ps *ps)
{
	int	half;
	int	i;
	int	j;
	int	count;

	if (ps->len_a <= 3)
		exit(0);
	half = ps->len_a / 2;
	i = 0;
	while (i < ps->len_a)
	{
		j = 0;
		count = 0;
		while (j < ps->len_a)
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

void	track_chunks(t_ps *ps)
{
	int	i;

	i = 0;
	if (ps->len_array == 1)
		ps->array[1] = 0;
	while (i < ps->len_array && ps->len_array > 1)
	{
		ps->array[ps->len_array - i] = ps->array[ps->len_array - (i + 1)];
		i++;
	}
	ps->array[0] = ps->count;
	ps->len_array++;
}
