/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:11:53 by yoonslee          #+#    #+#             */
/*   Updated: 2023/04/13 17:32:55 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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


/*1. Number of input is 1.
2. Number of input is 2. means a quoted string(split function)
3. Numbe of input is greater than 2.*/

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	get_real_args(argc, argv, &ps);
	ft_printf("result of real argc func: %d\n", ps.real_argc);
	ft_printf("result of real argv func: %s\n", ps.real_argv[0]);
	check_real_argv(&ps);
	return (0);
}
