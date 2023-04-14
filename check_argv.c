/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:54 by yoonslee          #+#    #+#             */
/*   Updated: 2023/04/14 15:12:26 by yoonslee         ###   ########.fr       */
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

int	ft_strlen_ps(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*Checks if argv is numbers only*/
void	arg_is_number(int i, int j, t_ps *ps)
{
	int				neg;
	long long int	res;

	while (i < ps->real_argc)
	{
		neg = 1;
		res = 0;
		j = 0;
		if (ps->real_argv[i][j] == '-')
			neg = -1;
		if (ps->real_argv[i][j] == '+' || ps->real_argv[i][j] == '-')
			j++;
		while (j < ft_strlen_ps(ps->real_argv[i]))
		{
			if (ft_isdigit(ps->real_argv[i][j]) == 0)
				ft_error();
			res = res * 10 + (ps->real_argv[i][j] - 48);
			// ft_printf("res is %d\n", res);
			j++;
		}
		// ft_printf("final res is %d\n", res);
		if ((neg * res) > 2147483647 || (neg * res) < -2147483648)
			ft_error();
		ps->real_argv[i][0] = neg * res;
		// ps->real_argv[i][1] = '\0';
		// ft_printf("real argv is %s\n", ps->real_argv[i]);
		i++;
	}
}

/* have_duplicates:
*   Checks if the argument list has duplicate numbers.
*   Return: error if a duplicate is found, 0 if there are none.
*/
static int	have_duplicates(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps->real_argc)
	{
		j = i + 1;
		while (j < ps->real_argc)
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	arg_is_number(i, j, ps);
	// ft_printf("errors args_number\n");
	if (have_duplicates(ps) != 0)
		return (0);
	// ft_printf("errors duplicates\n");
	return (1);
}
