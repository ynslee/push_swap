/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:20:20 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/04 13:08:25 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char const *s, char c)
{
	int	count_word;

	count_word = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count_word++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count_word);
}

int	get_real_argc(int argc, char **argv)
{
	int	i;
	int	real_argc;

	i = 1;
	real_argc = 0;
	while (i < argc)
	{
		real_argc += ft_count_words(argv[i], ' ');
		i++;
	}
	return (real_argc);
}

void	free_split_result(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
		free(str_array[i++]);
	free(str_array);
}

int	get_real_argv(t_ps *ps, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**split_result;

	i = 0;
	j = 1;
	while (i < ps->real_argc)
	{
		split_result = ft_split(argv[j++], ' ');
		k = 0;
		while (split_result[k] != NULL)
			ps->real_argv[i++] = ft_strdup(split_result[k++]);
		free_split_result(split_result);
	}
	return (1);
}

int	get_real_args(int argc, char **argv, t_ps *ps)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	ps->real_argc = get_real_argc(argc, argv);
	if (ps->real_argc == argc - 1)
		ps->real_argv = argv + 1;
	else
	{
		ps->real_argv = malloc((ps->real_argc + 1) * sizeof(char *));
		if (!ps->real_argv)
			return (0);
		get_real_argv(ps, argv);
	}
	return (1);
}
