/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:10:07 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:10:07 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_sorted(t_general *gen)
{
	int	i;

	i = 0;
	while (i < gen->length)
	{
		if (gen->stack_a->numbers[i] != i)
			return (0);
		i++;
	}
	return (1);
}

void	push_swap_advanced(t_general *gen, int divider)
{
	int	i;

	i = 0;
	while (i < divider)
	{
		push_to_stack_b(gen, divider, i);
		while (gen->stack_b->length > 0)
			push_to_stack_a(gen);
		i++;
	}
	final_touch(gen);
}
