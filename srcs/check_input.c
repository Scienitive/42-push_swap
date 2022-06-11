/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:52:33 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 15:49:01 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_numbers(char	**argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !(j == 0 && (argv[i][j] == '-'
						|| argv[i][j] == '+') && ft_isdigit(argv[i][j + 1])))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_if_int(char	**argv)
{
	int		i;
	long	max_int;
	long	min_int;

	i = 0;
	max_int = 2147483647;
	min_int = -2147483648;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11)
			return (-1);
		if (ft_atol(argv[i]) > max_int || ft_atol(argv[i]) < min_int)
			return (-1);
		i++;
	}
	return (0);
}

static int	check_duplicates(char	**argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strncmp(argv[i], argv[j], 12))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input(char **argv, int argv_plus)
{
	if (argv_plus)
		argv++;
	if (check_numbers(argv) == -1)
		return (-1);
	if (check_if_int(argv) == -1)
		return (-1);
	if (check_duplicates(argv) == -1)
		return (-1);
	return (0);
}
