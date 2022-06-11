/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:01:24 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 15:45:55 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

static void	free_split(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	errors_and_initialize(t_general	*gen, int argc, char **argv)
{
	char	***arr;
	char	**numbers;
	int		argv_plus;

	argv_plus = 1;
	arr = &argv;
	if (argc <= 1)
		print_error("");
	if (!ft_strlen(argv[1]))
		print_error("");
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		argv_plus = 0;
		numbers = ft_split(argv[1], ' ');
		arr = &numbers;
	}
	if (check_input(*arr, argv_plus) == -1)
	{
		if (argc == 2 && ft_strchr(argv[1], ' '))
			free_split(*arr);
		print_error("Error\n");
	}
	initialize(*arr, gen, argv_plus);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		free_split(*arr);
}

int	main(int argc, char **argv)
{
	t_general	gen;

	errors_and_initialize(&gen, argc, argv);
	if (!is_it_sorted(&gen))
	{
		if (gen.length <= 2 && gen.length > 1)
			push_swap_2(&gen);
		else if (gen.length <= 3 && gen.length > 1)
			push_swap_3(&gen, 1);
		else if (gen.length <= 5 && gen.length > 1)
			push_swap_5(&gen);
		else if (gen.length <= 75 && gen.length > 1)
			push_swap_advanced(&gen, 2);
		else if (gen.length <= 150 && gen.length > 1)
			push_swap_advanced(&gen, 3);
		else if (gen.length <= 500 && gen.length > 1)
			push_swap_advanced(&gen, 7);
	}
	free_everything(&gen);
}
