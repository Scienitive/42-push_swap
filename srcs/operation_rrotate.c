/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:10:34 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:10:36 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_general	*gen)
{
	int	temp;
	int	i;

	if (gen->stack_a->length > 1)
	{
		i = gen->stack_a->length - 1;
		temp = gen->stack_a->numbers[i];
		while (i > 0)
		{
			gen->stack_a->numbers[i] = gen->stack_a->numbers[i - 1];
			i--;
		}
		gen->stack_a->numbers[0] = temp;
	}
	print_operation(gen, "rra\n");
}

void	do_rrb(t_general	*gen)
{
	int	temp;
	int	i;

	if (gen->stack_b->length > 1)
	{
		i = gen->stack_b->length - 1;
		temp = gen->stack_b->numbers[i];
		while (i > 0)
		{
			gen->stack_b->numbers[i] = gen->stack_b->numbers[i - 1];
			i--;
		}
		gen->stack_b->numbers[0] = temp;
	}
	print_operation(gen, "rrb\n");
}

void	do_rrr(t_general	*gen)
{
	do_rra(gen);
	do_rrb(gen);
	print_operation(gen, "rrr\n");
}
