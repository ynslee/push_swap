/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:08 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/12 14:52:01 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check if stack A is sorted already. If not, continue to sort*/
void	sort_init(t_ps *ps)
{
	if (sorted_orderly(ps->a, ps->len_a) == 1)
		exit(0);
	if (ps->len_a <= 5)
	{
		ft_printf("----------number amount is same and smaller than 5 ---------\n");
		small_sort(ps);
		print_stack_a(ps);
		print_stack_b(ps);
		ft_printf("----------------------------------------------------\n");
		return ;
	}
	else if (ps->len_a > 5)
		sort_to_b(ps);
	ft_printf("----------sort the leftover of stack_a ---------\n");
	small_sort(ps);
	print_stack_a(ps);
	print_stack_b(ps);
	ft_printf("--------------------------------------------------\n");
	sort_continue(ps);
	return ;
}

/*find the median and push it to stack b*/
void	sort_to_b(t_ps *ps)
{
	int	len;
	int	b_before;
	int	i;

	i = 0;
	if (ps->len_a <= 5)
		return ;
	ft_printf("--------------cutting a to b -----------\n");
	b_before = ps->len_b;
	ps->count = 0;
	find_median_a(ps, ps->len_a);
	len = ps->len_a;
	ft_printf ("a_median is %d\n, length is %d\n", ps->median, len);
	while (i < len)
	{
		if (ps->a[0] <= ps->median || (ps->a[0] == ps->median && len % 2 == 0))
			pb(ps);
		else
			ra(ps);
		i++;
	}
	ft_printf ("a_median is %d\n", ps->median);
	ft_printf("count is %d\n", ps->len_b - b_before);
	add_to_chunks(ps, ps->len_b - b_before);
	print_stack_a(ps);
	print_stack_b(ps);
	print_array(ps);
	ft_printf("-----------------------------------------\n");
	if (ps->len_a > 5)
		sort_to_b(ps);
}

void	find_median(t_ps *ps)
{
	int	half;
	int	i;
	int	j;
	int	count;

	if (ps->len_a <= 3)
		return ;
	half = ps->len_a / 2;
	i = 0;
	while (i < ps->len_a)
	{
		j = 0;
		count = 1;
		while (j < ps->len_a)
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

