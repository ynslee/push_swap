/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:11:53 by yoonslee          #+#    #+#             */
/*   Updated: 2023/03/13 16:49:47 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1. no integer parameters - "Error\n"
2. duplicate parameteres - "Erro\n"
3. Greater than MAXINT && smaller than MININT- "Error\n"
4. without any parameters, display nothing and give the prompt back.
6. Run checker with valid parameters, and write an action with
one or several spaces before and/or after the action during
the instruction phase. The program must display "Error\n" on standarderror.
7. if it is one number, it is already sorted so you don't do anything but just return.
*/

void	create_data_stack()
{
	
}

int	main(int argc, char **argv)
{
	t_dlist_node	*head;

	if (argc == 1)
		return ;
	if (is_valid_input(argc, argv) == 1)
	head = ft_calloc(1, sizeof(t_dlist_node *));
	head->prev = NULL;
	head->value = 

	return (0);
}