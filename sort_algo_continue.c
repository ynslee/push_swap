/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_continue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:23:43 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/03 15:49:42 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_continue(t_ps *ps)
{
	if (ps->len_a <= 3)
		small_sort(ps);
	while (ps->array[0] != 0)
	{
		ps->count = ps->array[0];
		update_array(ps);
		top_small_sort(ps);
	}
// 	if (ps->array[i] <= 2)
// 		// while
		
}

/*if the chunk is small or less than 3, you continue into sorting.
if chunk is bigger, you cut it and send it back to a*/
void	top_small_sort(t_ps *ps)
{
	int	i;

	i = -1;
	if (ps->count == 2)
	{
		if (ps->stack_a[0] > ps->stack_a[1])
			sa(ps);
	}
	if (ps->count == 3)
	{
		pa(ps);
		pa(ps);
		pa(ps);	
		if (ps->stack_a[0] < ps->stack_a[2] && ps->stack_a[2] < ps->stack_a[1])
		{
			ra(ps);
			sa(ps);
			rra(ps);
			return (0);
		}
	}
	while (++i < ps->count)
		pa(ps);
}

void	update_array(t_ps *ps)
{
	int	i;

	i = 0;
	while (ps->stack_a[i] != 0)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
}
