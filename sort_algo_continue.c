/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_continue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:23:43 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/09 14:43:06 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sort the small chunk in a and push back small chunk from b to a*/
void	sort_continue(t_ps *ps)
{
	int	temp;

	if (ps->len_a <= 5)
		small_sort(ps);
	print_stacks(ps);
	while (ps->array[0] != 0)
	{
		ps->count = ps->array[0];
		ft_printf("array[0] is %d\n", ps->count);
		temp = ps->count;
		if (sorted_reverse(ps->b, temp) == 1)
		{
			while (temp-- >= 0)
				pa(ps);
			return ;
		}
		if (ps->count <= 3)
			top_sort_b(ps);
		ft_printf("here5\n");
		if (ps->count > 3)
			divide_to_a(ps, ps->count);
		update_array(ps);
	}
// 	print_stacks(ps);
}

/*if the chunk is small or less than 3, you continue into sorting.
if chunk is bigger, you cut it and send it back to a*/
void	top_sort_b(t_ps *ps)
{
	if (ps->count == 2)
	{
		if (ps->b[0] < ps->b[1])
			sb(ps);
	}
	if (ps->count == 3 && ps->b[0] > ps->b[1] && ps->b[0] > ps->b[2])
	{
		pa(ps);
		sb(ps);
	}
	if (ps->count == 3 && ps->b[2] > ps->b[1] && ps->b[2] > ps->b[0])
	{
		if (ps->b[0] < ps->b[1])
			sb(ps);
		rb(ps);
		sb(ps);
		pa(ps);
		rrb(ps);
	}
	if (ps->count == 3 && ps->b[1] > ps->b[0] && ps->b[1] > ps->b[2])
		top_sort_b2(ps);
	pa(ps);
	pa(ps);
}

void	top_sort_b2(t_ps *ps)
{
	sb(ps);
	pa(ps);
	if (ps->b[0] < ps->b[1])
		sb(ps);
}

void	update_array(t_ps *ps)
{
	int	i;

	i = 0;
	while (ps->array[i] != 0)
	{
		ps->array[i] = ps->array[i + 1];
		i++;
	}
}
