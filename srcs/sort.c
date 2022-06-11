/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:37:20 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:11:11 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_string_array_length(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	*str_to_int_array(char **argv, int arr_len)
{
	int	*numbers;
	int	i;

	numbers = malloc(arr_len * sizeof(int));
	i = -1;
	while (argv[++i])
		numbers[i] = ft_atoi(argv[i]);
	return (numbers);
}

static int	*sort_numbers(int *numbers, int arr_len)
{
	int	*s_numbers;
	int	i;
	int	temp;

	s_numbers = copy_array(numbers, arr_len);
	i = 1;
	while (i < arr_len)
	{
		if (i != 0 && s_numbers[i] < s_numbers[i - 1])
		{
			temp = s_numbers[i];
			s_numbers[i] = s_numbers[i - 1];
			s_numbers[i - 1] = temp;
			i -= 2;
		}
		i++;
	}
	return (s_numbers);
}

static int	*make_index_arr(int *numbers, int *s_numbers, int arr_len)
{
	int	i;
	int	j;
	int	*index_arr;

	i = 0;
	index_arr = malloc(arr_len * sizeof(int));
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{
			if (numbers[i] == s_numbers[j])
			{
				index_arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (index_arr);
}

void	initialize(char **argv, t_general *gen, int argv_plus)
{
	int		*v_numbers;
	int		*s_numbers;
	int		*empty_numbers;
	char	*str1;
	char	*str2;

	if (argv_plus)
		argv++;
	init_stacks(gen);
	gen->length = get_string_array_length(argv);
	str1 = malloc(5 * sizeof(char));
	str2 = malloc(5 * sizeof(char));
	str1[0] = '\0';
	str2[0] = '\0';
	gen->o1 = str1;
	gen->o2 = str2;
	v_numbers = str_to_int_array(argv, gen->length);
	s_numbers = sort_numbers(v_numbers, gen->length);
	gen->stack_a->numbers = make_index_arr(v_numbers, s_numbers, gen->length);
	gen->stack_a->length = gen->length;
	empty_numbers = malloc(gen->length * sizeof(int));
	gen->stack_b->numbers = empty_numbers;
	gen->stack_b->length = 0;
	free(v_numbers);
	free(s_numbers);
}
