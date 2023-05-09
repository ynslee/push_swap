/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:35:26 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/09 15:35:51 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_ps	*ps)
{
	ps->len = ps->real_argc;
	if (ps->real_argc <= 1)
		exit(0);
	ps->a = malloc(sizeof(int) * ps->len);
	ps->b = malloc(sizeof(int) * ps->len);
	ps->array = malloc(sizeof(int) * 1);
	if (!ps->a || !ps->b || !ps->array)
	{
		msg_error("malloc error", 1);
		exit(0);
	}
	ps->number_amount = 0;
	ps->len_a = ps->real_argc;
	ps->len_b = 0;
	ps->median = 0;
	ps->len_array = 1;
	ps->array[0] = 0;
	ps->count = 0;
	return (1);
}
