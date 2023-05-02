/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:01:34 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/02 13:16:39 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_orderly(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	sorted_reverse(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] < array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
