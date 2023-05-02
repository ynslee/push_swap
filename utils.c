/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:36:09 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/02 16:36:27 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_ps *ps)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (i < ps->len_a)
	{
		if (ps->stack_a[temp] > ps->stack_a[i])
			temp = i;
		i++;
	}
	return (temp);
}

void	five_element(t_ps *ps)
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

void	sort_init(t_ps *ps)
{
	if (ps->len_a <= 5)
		small_sort(ps);
	// // if (sorted_reverse(ps->stack_a, ps->len_a) == 1)
	// // 	sort_reversesort(ps);
	else
		sort_algo(ps);
	return ;
}


