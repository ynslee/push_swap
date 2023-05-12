/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonseonlee <yoonseonlee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:08 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/11 21:15:25 by yoonseonlee      ###   ########.fr       */
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
	int b_before;

	ft_printf("--------------cuting a to b -----------\n");
	if(ps->len_a <= 5)
		return ;
	b_before = ps->len_b;
	ps->count = 0;
	find_median_a(ps, ps->len_a);
	len = ps->len_a;
	while ((ps->len_b - b_before) < (len / 2))
	{
		if (ps->a[0] < ps->median || (ps->a[0] == ps->median && len % 2 == 0))
			pb(ps);
		else
			check_rotate(ps);
	}
	ft_printf ("a_median is %d\n", ps->median);
	ft_printf("count is %d\n", ps->len_b - b_before);
	add_to_chunks(ps, ps->len_b - b_before);
	print_stack_a(ps);
	print_stack_b(ps);
	print_array(ps);
	ft_printf("-----------------------------------------\n");
	if (ps->len_a > 3)
		sort_to_b(ps);
}

void	find_median(t_ps *ps)
{
	int	half;
	int	i;
	int	j;
	int	count;

	if (ps->len_a <= 3)
		exit(0);
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

