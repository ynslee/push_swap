/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:08 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/09 14:41:16 by yoonslee         ###   ########.fr       */
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
	else if (ps->len_a > 5)
		sort_to_b(ps);
	sort_continue(ps);
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
	ft_printf("median is %d\n", ps->median);
	length = ps->len_a;
	ft_printf("length is %d\n", length);
	while (i < length)
	{
		if (ps->a[0] < ps->median)
		{
			pb(ps);
			ps->count++;
		}
		else
			check_rotate(ps);
		i++;
	}
	track_chunks(ps);
	if (ps->len_a > 5)
		sort_to_b(ps);
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
		count = 1;
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
