/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonseonlee <yoonseonlee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:03 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/16 09:22:32 by yoonseonlee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*move the chunks back to stack_a*/
void	divide_b_to_a(t_ps *ps, int length, int a_before, int count)
{
	int	i;

	i = 0;
	ps->count = 0;
	ft_printf("----------------cutting b to a -------------\n");
	find_median_b(ps, length);
	ft_printf ("b_median is %d\n", ps->median);
	ft_printf ("ps->b[0] is %d, b[1] is %d\n", ps->b[0], ps->b[1]);
	while (i < length)
	{
		if (ps->b[0] > ps->median)
			pa(ps);
		else
		{	
			ps->count++;
			rb(ps);
		}
		i++;
	}
	count = ps->count;
	add_to_chunks(ps, ps->count);
	while (count-- > 0 && length != ps->len_b)
		rrb(ps);
	ft_printf("count is %d\n", ps->count);
	print_stack_a(ps);
	print_stack_b(ps);
	print_array(ps);
	i = ps->len_a - a_before;
	if (i <= 3)
	{
		ft_printf("\n----------sort top a before divide a_to_b---------\n");
		top_sort_a(ps, i);
		print_stack_a(ps);
		print_stack_b(ps);
		print_array(ps);
		ft_printf("------------------------ended-------------------------\n");
		return ;
	}
	if (ps->len_a - a_before > 3)
		divide_a_to_b(ps, ps->len_a - a_before);
}

/*move the chunks back to stack_b after moving it to stack_a*/
void	divide_a_to_b(t_ps *ps, int a_leftover)
{
	int	i;
	int	length;

	i = 0;
	ps->count = 0;
	if (sorted_orderly(ps->a, ps->len_a) == 1)
		return ;
	ft_printf("----------cuting a again to b ---------\n");
	find_median_a(ps, a_leftover);
	ft_printf ("a_median is %d\n", ps->median);
	length = a_leftover;
	while (length-- > 0)
	{
		if (ps->a[0] < ps->median || (ps->a[0] == ps->median && a_leftover % 2 == 0))
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
	divide_a_to_b2(ps, i, a_leftover - ps->count);
}

void	divide_a_to_b2(t_ps *ps, int i, int leftover)
{
	while (i-- > 0)
		rra(ps);
	if (leftover <= 3)
	{
		ft_printf("----------just sorts a becasue it is smaller than 3---------\n");
		top_sort_a(ps, leftover);
		print_stack_a(ps);
		print_stack_b(ps);
		print_array(ps);
		ft_printf("------------------------ended-------------------------\n");
	}
	add_to_chunks(ps, ps->count);
	print_stack_a(ps);
	print_stack_b(ps);
	print_array(ps);
	if (leftover <= 3 && ps->count <= 3)
	{
		ft_printf("----------just sorts b becasue top is smaller than 3---------\n");
		top_sort_b(ps);
		remove_from_chunks(ps);
		print_stack_a(ps);
		print_stack_b(ps);
		print_array(ps);
	}
	ft_printf("what is left in a is %d\n", leftover);
	if (leftover > 3)
		divide_a_to_b(ps, leftover);
	ft_printf("---------------------------------------\n");
}

/*sort top 2 or 3 of the stack_a*/
void	top_sort_a(t_ps *ps, int length)
{
	ft_printf("getting in to top sort a\n");
	ft_printf("what is the length? %d\n", length);
	if (sorted_orderly(ps->a, ps->len_a) == 1 || length == 1)
		return ;
	else if (length == 2 && ps->a[0] > ps->a[1])
	{
		sa(ps);
		return ;
	}
	else if (length == 3 && ps->a[0] < ps->a[1] && ps->a[0] < ps->a[2])
	{	
		pb(ps);
		sa(ps);
	}
	else if (length == 3 && ps->a[2] < ps->a[1] && ps->a[2] < ps->a[0])
	{
		if (ps->a[0] > ps->a[1])
			sa(ps);
		ra(ps);
		sa(ps);
		pb(ps);
		rra(ps);
	}		
	else if (length == 3 && ps->a[1] < ps->a[0] && ps->a[1] < ps->a[2])
	{
		if (ps->a[0] < ps->a[2])
		{
			sa(ps);
			return ;
		}
		else
		{
			sa(ps);
			pb(ps);
			sa(ps);
		}
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
		exit(0);
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

void	free_all(t_ps *ps)
{
	// ft_printf("array=%p\n", ps->array);
	// ft_printf("a=%p\n", ps->a);
	// ft_printf("b=%p\n", ps->b);
	if (ps->array)
		free(ps->array);
	if (ps->a)
		free(ps->a);
	if (ps->b)
		free(ps->b);
	// if (ps->real_argv)
	// 	free_char_array(ps);
	ps->array = NULL;
	ps->a = NULL;
	ps->b = NULL;
}

void	free_char_array(t_ps *ps)
{
	int	i;

	i = 0;

	while (ps->real_argv[i] != NULL)
	{
		free(ps->real_argv[i]);
		ps->real_argv[i] = NULL;
		i++;
	}
	free(ps->real_argv);
}
