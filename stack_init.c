/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:35:26 by yoonslee          #+#    #+#             */
/*   Updated: 2023/04/17 17:20:13 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*return (0) = false
return (1) = true*/

// t_node	*newnode(t_node *prev, int value)
// {
// 	t_node	*new;

// 	new = (t_node *)malloc(sizeof(t_node));
// 	if (!new)
// 		return (0);
// 	new->value = value;
// 	new->prev = prev;
// 	new->next = NULL;
// 	return (new);
// }

// int	init_stack(t_node **stack_a, t_node **stack_b)
// {
// 	*stack_a = newnode(NULL, 0);
// 	if (!*stack_a)
// 		return (0);
// 	*stack_b = newnode(NULL, 0);
// 	if (!*stack_b)
// 	{
// 		free(*stack_a);
// 		return (0);
// 	}
// 	(*stack_b)->next = *stack_b;
// 	(*stack_b)->prev = *stack_b;
// 	return (1);
// }

int	init_stack(t_ps	*ps)
{
	ps->len = ps->real_argc + 1;
	if (ps->real_argc <= 1)
		exit(0);
	ps->stack_a = malloc(sizeof(int) * ps->len);
	ps->stack_b = malloc(sizeof(int) * ps->len);
	if (!ps->stack_a || !ps->stack_b)
	{
		msg_error("malloc error", 1);
		exit(0);
	}
	ps->number_amount = 0;
	ps->len_a = ps->real_argc;
	ps->len_b = 0;
	return (1);
}
