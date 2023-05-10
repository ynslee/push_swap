/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:39:16 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/10 11:41:58 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_chunks(t_ps *ps, int num)
{
	int	i;
	int	*new;

	i = 1;
	new = ft_calloc((ps->len_array + 1), sizeof(int));
	if (!new)
		msg_error("calloc failure", 1);
	while (i < ps->len_array + 1)
	{
		new[i] = ps->array[i - 1];
		i++;
	}
	new[0] = num;
	free(ps->array);
	ps->array = new;
	ps->len_array++;
}

void	remove_from_chunks(t_ps	*ps)
{
	int	i;
	int	*new;

	i = 0;
	new = ft_calloc((ps->len_array - 1), sizeof(int));
	if (!new)
		msg_error("calloc failure", 1);
	while (i < ps->len_array - 1)
	{
		new[i] = ps->array[i + 1];
		i++;
	}
	free(ps->array);
	ps->array = new;
	ps->len_array--;
}
