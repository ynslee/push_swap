/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:36:09 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/03 14:24:59 by yoonslee         ###   ########.fr       */
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

void	print_stacks(t_ps *ps)
{
	int	i;

	i = 0;
	ft_printf("stack a length is %d\n", ps->len_a);
	ft_printf("stack a is ");
	while (i < ps->len_a)
	{
		ft_printf("%d ", ps->stack_a[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("stack b length is %d\n", ps->len_b);
	i = 0;
	ft_printf("stack b is ");
	while (i < ps->len_b)
	{
		ft_printf("%d ", ps->stack_b[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("array is ");
	while (i < ps->len_array)
	{
		ft_printf("%d ", ps->array[i]);
		i++;
	}
	ft_printf("\n");
}
