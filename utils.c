/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:36:09 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/12 11:10:51 by yoonslee         ###   ########.fr       */
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
		if (ps->a[i] < ps->a[temp])
				temp = i;
		i++;
	}
	return (temp);
}

void	reverse_sort(t_ps *ps, int length)
{
	while (length-- > 0)
		pa(ps);
	return ;
}

void	check_rotate(t_ps *ps)
{
	int	i;
	int	temp;	

	if (ps->a[0] >= ps->median)
	{
		i = 1;
		while (i < ps->len_a)
		{
			if (ps->a[i] < ps->median && i <= (ps->len_a / 2))
			{
				temp = i;
				while (temp-- > 0)
					ra(ps);
				return ;
			}
			else if (ps->a[i] < ps->median && i > (ps->len_a / 2))
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

void	print_stack_a(t_ps *ps)
{
	int	i;

	i = 0;
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("stack a is   ");
	while (i < ps->len_a)
	{
		ft_printf("%d  ", ps->a[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_stack_b(t_ps *ps)
{
	int	i;

	i = 0;
	ft_printf("\n");
	ft_printf("stack b is   ");
	while (i < ps->len_b)
	{
		ft_printf("%d  ", ps->b[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("\n");
}

void	print_array(t_ps *ps)
{
	int	i;

	i = 0;
	ft_printf("stack a length is %d\n", ps->len_a);
	ft_printf("stack b length is %d\n", ps->len_b);
	ft_printf("array is ");
	while (i < ps->len_array)
	{
		ft_printf("%d ", ps->array[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("\n");
}

void	find_median_b(t_ps *ps, int len)
{
	int	half;
	int	i;
	int	j;
	int	count;

	if (len <= 2)
		return ;
	half = len / 2;
	i = 0;
	while (i < len)
	{
		j = 0;
		count = 0;
		while (j < len)
		{
			if ((ps->b[i] < ps->b[j]) && i != j)
				count++;
			j++;
		}
		if (half == count)
			ps->median = ps->b[i];
		i++;
	}
}
