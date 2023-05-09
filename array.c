/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:39:16 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/09 15:54:16 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_track(t_ps *ps, int num)
{
	int	i;
	int	*add;

	i = 1;
	add = malloc(sizeof(int) * (ps->len_array + 1));
	if (!add)
		error("malloc failure", 1);
	while (i < ps->len_array + 1)
	{
		add[i] = ps->array[i - 1];
		i++;
	}
	add[0] = num;
	free(ps->array);
	ps->array = add;
	ps->len_array++;
}

void	track_chunks(t_ps *ps)
{
	int	i;

	i = 0;
	add_number_array(ps, ps->count);
	if (ps->len_array == 1)
		ps->array[1] = 0;
	while (i < ps->len_array && ps->len_array > 1)
	{
		ps->array[ps->len_array - i] = ps->array[ps->len_array - (i + 1)];
		i++;
	}
	ps->array[0] = ps->count;
	ps->len_array++;
}
