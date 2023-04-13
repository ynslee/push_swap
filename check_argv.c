/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:54 by yoonslee          #+#    #+#             */
/*   Updated: 2023/04/13 17:42:59 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. no integer parameters - "Error\n"
2. duplicate parameteres - "Error\n"
3. Greater than MAXINT && smaller than MININT- "Error\n"
4. without any parameters, display nothing and give the prompt back.
6. Run checker with valid parameters, and write an action with
one or several spaces before and/or after the action during
the instruction phase. The program must display "Error\n" on standarderror.
7. if it is one number, it is already sorted so you don't do anything but just return.
*/

#include "push_swap.h"

/*Checks if argv is numbers only*/
static int	arg_is_number(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps->real_argc)
	{
		j = 0;
		while (ps->real_argv[i][j] != NULL)
		{
			if (j == 0)
		
			j++;
		}
	}
}

/* have_duplicates:
*   Checks if the argument list has duplicate numbers.
*   Return: 1 if a duplicate is found, 0 if there are none.
*/
static int	have_duplicates(t_ps *ps)
{
	int	i;
	int	j;

	i = 1;
	while (ps->real_argv[i])
	{
		j = 1;
		while (ps->real_argv[j])
		{
			if (j != i && ft_strcmp(ps->real_argv[i], ps->real_argv[j]) == 0)
				ft_error();
			j++;
		}
		i++;
	}
	return (0);
}

/*  Checks if the given arguments are all numbers, without duplicates.
*   Return: 1 if the arguments are valid, 0 if not.*/
int	check_real_argv(t_ps *ps)
{
	if (!arg_is_number(ps))
		return (0);
	if (have_duplicates(ps))
		return (0);
	return (1);
}
