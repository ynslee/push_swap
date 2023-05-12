/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonseonlee <yoonseonlee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:03 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/11 21:38:29 by yoonseonlee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*move the chunks back to stack_a*/
void	divide_b_to_a(t_ps *ps, int length, int a_before, int count)
{
	ps->count = 0;
	ft_printf("--------------cuting b to a -----------\n");
	find_median_b(ps, length);
	ft_printf ("b_median is %d\n", ps->median);
	while (ps->len_a - a_before < length / 2)
	{
		if (ps->b[0] > ps->median || ((ps->b[0] > ps->median) && (length % 2 == 0)))
			pa(ps);
		else
		{	
			ps->count++;
			rb(ps);
		}
	}
	count = ps->count;
	ft_printf("count is %d\n", count);
	add_to_chunks(ps, ps->count);
	while (count-- > 0 && length != ps->len_b)
		rrb(ps);
	print_stack_a(ps);
	print_stack_b(ps);
	print_array(ps);
	ft_printf("----------------ended------------------\n");
	if (ps->len_a - a_before <= 3)
	{
		top_sort_a(ps, ps->len_a - a_before);
		return ;
	}
	divide_a_to_b(ps, ps->len_a - a_before);
}

/*move the chunks back to stack_b after moving it to stack_a*/
void	divide_a_to_b(t_ps *ps, int a_leftover)
{
	int	i;

	i = 0;
	ps->count = 0;
	if (sorted_orderly(ps->a, ps->len_a) == 1)
		return ;
	ft_printf("----------cuting a again to b ---------\n");
	if (a_leftover <= 3)
	{
		ft_printf("----------just sorts a becasue it is smaller than 3---------\n");
		top_sort_a(ps, a_leftover);
		print_stack_a(ps);
		print_stack_b(ps);
		print_array(ps);
		ft_printf("------------------------ended-------------------------\n");
		return ;
	}
	find_median_a(ps, a_leftover);
	divide_a_to_b2(ps, i, a_leftover);
}

void	divide_a_to_b2(t_ps *ps, int i, int leftover)
{
	int	length;

	length = leftover;
	while (length-- > 0)
	{
		if (ps->a[0] < ps->median)
		{
			pb(ps);
			ps->count++;
		}
		else if (ps->a[0] == ps->median && leftover % 2 == 0)
		{
			pb(ps);
			ps->count++;
		}
		else if (ps->a[0] >= ps->median)
		{
			ra(ps);
			i++;
		}
	}
	while (i-- > 0)
		rra(ps);
	add_to_chunks(ps, ps->count);
	print_stack_a(ps);
	print_stack_b(ps);
	print_array(ps);
	if ((leftover - ps->count) > 3)
		divide_a_to_b(ps, leftover - ps->count);
	ft_printf("-----------------ended-----------------\n");
}

/*sort top 2 or 3 of the stack_a*/
void	top_sort_a(t_ps *ps, int length)
{
	if (sorted_orderly(ps->a, ps->len_a) == 1)
		return ;
	if (length == 2)
		sa(ps);
	if (length == 3 && ps->a[0] < ps->a[1] && ps->a[0] < ps->a[2])
	{	
		pb(ps);
		sa(ps);
	}
	if (length == 3 && ps->b[2] < ps->b[1] && ps->b[2] < ps->b[0])
	{
		sa(ps);
		pb(ps);
		if (ps->a[0] > ps->a[1])
			sa(ps);
	}
	if (length == 3 && ps->b[1] > ps->b[0] && ps->b[1] > ps->b[2])
	{
		if (ps->a[0] > ps->a[1])
			sa(ps);
		ra(ps);
		sa(ps);
		pb(ps);
		rra(ps);
	}
	pa(ps);
}

void	find_median_a(t_ps *ps, int len)
{
	int	half;
	int	i;
	int	j;
	int	count;

	if (len <= 3)
		ft_printf("length of 3 numbers were not handled properly");
	half = len / 2;
	i = 0;
	while (i < len)
	{
		j = 0;
		count = 0;
		while (j < len)
		{
			if (ps->a[i] < ps->a[j] && i != j)
				count++;
			j++;
		}
		if (half == count)
			ps->median = ps->a[i];
		i++;
	}
}
