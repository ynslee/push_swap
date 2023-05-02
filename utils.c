/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:36:09 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/02 15:38:55 by yoonslee         ###   ########.fr       */
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

/*find the medium and push it to other stack*/
void	sort_algo(t_ps *ps)
{
	int	i;

	i = 0;
	ps->medium = find_medium(ps, i);
	ft_printf("medium is %d\n", ps->medium);
	while (i < ps->len_a - 1)
	{
		if (ps->stack_a[i] <= ps->medium)
			pb(ps);
		i++;
	}
	ft_printf("error!\n");
	if (ps->len_a > 3)
		sort_algo(ps);
}

int	find_medium(t_ps *ps, int i)
{
	int	temp;
	int	j;

	ps->array = ps->stack_a;
	while (i < ps->len_a - 1)
	{
		while (j < ps->len_a - i - 1)
		{
			j = 0;
			if (ps->array[j] > ps->array[j + 1])
			{
				temp = ps->array[j];
				ps->array[j] = ps->array[j + 1];
				ps->array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	if (ps->len_a % 2 != 0)
		temp = ps->array[ps->len_a / 2];
	else
		temp = ps->array[(ps->len_a - 1) / 2];
	ps->array = NULL;
	return (temp);
}
