/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:35:26 by yoonslee          #+#    #+#             */
/*   Updated: 2023/04/12 10:50:30 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*return (0) = false
return (1) = true*/

t_dlist	*newdlist(t_dlist *prev, int value)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (0);
	new->value = value;
	new->index = 0;
	new->prev = prev;
	new->next = NULL;
	return (new);
}

int	init_stack(t_dlist **stack_a, t_dlist **stack_b)
{
	*stack_a = newdlist(NULL, 0);
	if (!*stack_a)
		return (0);
	*stack_b = newdlist(NULL, 0);
	if (!*stack_b)
	{
		free(*stack_a);
		return (0);
	}
	(*stack_b)->next = *stack_b;
	(*stack_b)->prev = *stack_b;
	return (1);
}