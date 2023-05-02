/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:08 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/02 16:42:13 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*find the medium and push it to other stack*/
void	sort_algo(t_ps *ps)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	ps->medium = find_median(ps);
	ft_printf("length is %d\n", ps->len_a);
	ft_printf("median is %d\n", ps->medium);
	while (i < ps->len_a - 1)
	{
		if (ps->stack_a[i] <= ps->medium)
			pb(ps);
		i++;
	}
	// if (ps->len_a > 3)
	// 	sort_algo(ps);
}

int	find_median(t_ps *ps)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (i++ < ps->len_a)
		ps->array[i] = ps->stack_a[i];
	i = -1;
	while (i++ < ps->len_a - 1)
	{
		j = 0;
		while (j < ps->len_a - i - 1)
		{
			if (ps->array[j] > ps->array[j + 1])
			{
				temp = ps->array[j];
				ps->array[j] = ps->array[j + 1];
				ps->array[j + 1] = temp;
			}
			j++;
		}
	}
	temp = find_median2(ps);
	return (temp);
}

int	find_median2(t_ps *ps)
{
	int	temp;

	if (ps->len_a % 2 != 0)
		temp = ps->array[ps->len_a / 2];
	else
		temp = ps->array[(ps->len_a - 1) / 2];
	ps->array = NULL;
	return (temp);
}
