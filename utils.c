/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:36:09 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/04 13:08:25 by yoonslee         ###   ########.fr       */
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
		if (ps->a[temp] > ps->a[i])
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

void	check_rotate(t_ps *ps)
{
	int	i;
	int	temp;	

	i = 0;
	if (ps->a[0] > ps->median)
	{
		while (i < ps->len_a)
		{
			if (ps->a[i] <= ps->median && i < (ps->len_a / 2))
			{
				temp = i;
				while (temp-- > 0)
					ra(ps);
				return ;
			}
			else if (ps->a[i] <= ps->median && i > (ps->len_a / 2))
			{
				temp = i;
				while (temp-- > 0)
					rra(ps);
				return ;
			}
			i++;
		}
	}
}

int	sorted_reverse(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}


void	print_stacks(t_ps *ps)
{
	int	i;

	i = 0;
	ft_printf("stack a length is %d\n", ps->len_a);
	ft_printf("stack a is ");
	while (i < ps->len_a)
	{
		ft_printf("%d ", ps->a[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("stack b length is %d\n", ps->len_b);
	i = 0;
	ft_printf("stack b is ");
	while (i < ps->len_b)
	{
		ft_printf("%d ", ps->b[i]);
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
