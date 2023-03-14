/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:54 by yoonslee          #+#    #+#             */
/*   Updated: 2023/03/14 16:02:16 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "push_swap.h"

void	arg_check(int argc, char **argv)
{
	if (argc == 1 || argc == 2)
		return ;
	if (argc > 2)
	{
		arg_is_number(argv);
	}
}

static int	arg_is_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if ((argv[i][j] == '+' || argv[i][j] == '-' ) && argv[i][j + 1] != '\0')
		j++;
	while (argv[i] && ft_isdigit(argv[i][j]))
	{
		while (argv[i][j] && (ft_isdigit(argv[i][j]) == 1))
		{
			if (ft_isdigit(argv[i][j]) == 0)
				//exit
		}
		i++;
	}
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

/* have_duplicates:
*   Checks if the argument list has duplicate numbers.
*   Return: 1 if a duplicate is found, 0 if there are none.
*/
static int	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nbstr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_double(char *str, char c, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	int	i;
	int	i2;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			i2 = 0;
			while (argv[2][i2] != '\0')
			{
				if (argv[1][i] == argv[2][i2])
				{
					if (check_if_double(argv[1], argv[1][i], i))
					{
						write (1, &argv[1][i], 1);
						break ;
					}
				}
				i2++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
}

/*  Checks if the given arguments are all numbers, without duplicates.
*   Return: 1 if the arguments are valid, 0 if not.*/
int	check_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	if (!arg_is_number(argv[i]))
		return (0);
	if (have_duplicates(argv))
		return (0);
	return (1);
}