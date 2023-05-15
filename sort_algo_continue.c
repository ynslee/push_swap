/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_continue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:23:43 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/15 16:08:37 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sort the small chunk in a and push back small chunk from b to a*/
void	sort_continue(t_ps *ps)
{
	int	temp;
	int	a_before;

	a_before = ps->len_a;
	ft_printf("--------------before cutting stacks-----------\n");
	print_stack_a(ps);
	print_stack_b(ps);
	print_array(ps);
	ft_printf("----------------------------------------------\n");
	ps->count = 0;
	while (ps->array[0] != 0)
	{
		ft_printf("-------------Loop through %d nums in b-----------\n", ps->array[0]);
		ps->count = ps->array[0];
		temp = ps->count;
		if (sorted_reverse(ps->b, temp) == 1)
		{
			ft_printf("-------------if array[0] of stack_b is reversed, sort it back-----------\n");
			reverse_sort(ps, temp);
			remove_from_chunks(ps);
			print_stack_a(ps);
			print_stack_b(ps);
			print_array(ps);
			ft_printf("------------------------------------------------------------------------\n");
		}
		else if (ps->count <= 3)
		{
			ft_printf("--------sorting top 3 of stack_b and before cutting from stack_b--------\n");
			top_sort_b(ps);
			remove_from_chunks(ps);
			print_stack_a(ps);
			print_stack_b(ps);
			print_array(ps);
			ft_printf("------------------------------------------------------------------------\n");
		}
		if (ps->count > 3)
		{
			remove_from_chunks(ps);
			divide_b_to_a(ps, ps->count, ps->len_a, temp);
		}
	}
	print_stack_a(ps);
	print_stack_b(ps);
	print_array(ps);
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
