/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:11:26 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:11:27 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(int *arr, int arr_len)
{
	int	*new_arr;
	int	i;

	i = 0;
	new_arr = malloc(arr_len * sizeof(int));
	while (i < arr_len)
	{
		new_arr[i] = arr[i];
		i++;
	}
	return (new_arr);
}

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

static void	sign_maker(const char *str, int *sign, size_t *i)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		*i += 1;
	}
	else if (str[*i] == '+')
	{
		*sign = 1;
		*i += 1;
	}
	else if (str[*i] >= '0' && str[*i] <= '9')
		*sign = 1;
}

long	ft_atol(const char *str)
{
	size_t	i;
	int		sign;
	long	ans;

	ans = 0;
	sign = 0;
	i = 0;
	while (is_whitespace(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (sign == 0)
			sign_maker(str, &sign, &i);
		if (str[i] < '0' || str[i] > '9')
			break ;
		ans *= 10;
		ans += (str[i] - '0') * sign;
		i++;
	}
	return (ans);
}
