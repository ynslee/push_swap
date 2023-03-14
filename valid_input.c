/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:54 by yoonslee          #+#    #+#             */
/*   Updated: 2023/03/13 14:53:07 by yoonslee         ###   ########.fr       */
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


int	arg_is_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if ((argv[i][j] == '+' || argv[i][j] == '-' ) && argv[i][j + 1] != '\0')
	{
		j++;
		while (argv[i][j] && ft_isdigit(argv[i][j]))
		{
			
		}
	}
	return (1);
}

/* have_duplicates:
*   Checks if the argument list has duplicate numbers.
*   Return 0 if no duplicates
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
			if (j != i && ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* arg_is_zero:
*   Checks the argument is a 0 to avoid 0 +0 -0 duplicates
*	and 0 0000 +000 -00000000 too.
*   Return: 1 if the argument is a zero, 0 if it contains
*	anything else than a zero.
*/
int	number_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

/* is_valid_input:
*   Checks if the given arguments are all numbers, without duplicates.
*   Return: 1 if the arguments are valid, 0 if not.
*/
int	is_valid_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while(i < argc) 
	{
		while(argv[i][j])
		{
			if (!arg_is_valid(argv[i]))
				return (0);
			j++;
		}
		i++;
	}
	if (have_duplicates(argv))
		return (0);
	return (1);
}



