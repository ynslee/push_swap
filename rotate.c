/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:00:09 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/04 13:08:25 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	int	i;
	int	temp;

	i = 0;
	if (ps->len_a < 2)
		return ;
	temp = ps->a[0];
	while (i < ps->len_a - 1)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->a[i] = temp;
	ps->number_amount++;
	i = 0;
	// while (i < ps->len_a)
	// {
	// 	ft_printf("now stack a[%d] is %d\n", i, ps->a[i]);
	// 	i++;
	// }
	ft_putstr_fd("ra\n", 2);
}

void	rb(t_ps *ps)
{
	int	i;
	int	temp;

	i = 0;
	if (ps->len_b < 2)
		return ;
	temp = ps->b[0];
	while (i < ps->len_b - 1)
	{
		ps->b[i] = ps->b[i + 1];
		i++;
	}
	ps->b[i] = temp;
	ps->number_amount++;
	i = 0;
	ft_putstr_fd("rb\n", 2);
}

void	rr(t_ps *ps)
{
	if (ps->len_a < 2 || ps->len_b < 2)
		return ;
	ra(ps);
	rb(ps);
	ps->number_amount++;
	ft_putstr_fd("rr\n", 2);
}
