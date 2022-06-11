/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:09:55 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:10:20 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_general	*gen)
{
	int	i;
	int	num;

	if (gen->stack_a->length > 0)
	{
		num = gen->stack_a->numbers[0];
		i = 1;
		while (gen->stack_a->length > i)
		{
			gen->stack_a->numbers[i - 1] = gen->stack_a->numbers[i];
			i++;
		}
		gen->stack_a->length--;
		i = gen->stack_b->length;
		while (i > 0)
		{
			gen->stack_b->numbers[i] = gen->stack_b->numbers[i - 1];
			i--;
		}
		gen->stack_b->numbers[0] = num;
		gen->stack_b->length++;
	}
	print_operation(gen, "pb\n");
}

void	do_pa(t_general	*gen)
{
	int	i;
	int	num;

	if (gen->stack_b->length > 0)
	{
		num = gen->stack_b->numbers[0];
		i = 1;
		while (gen->stack_b->length > i)
		{
			gen->stack_b->numbers[i - 1] = gen->stack_b->numbers[i];
			i++;
		}
		gen->stack_b->length--;
		i = gen->stack_a->length;
		while (i > 0)
		{
			gen->stack_a->numbers[i] = gen->stack_a->numbers[i - 1];
			i--;
		}
		gen->stack_a->numbers[0] = num;
		gen->stack_a->length++;
	}
	print_operation(gen, "pa\n");
}
