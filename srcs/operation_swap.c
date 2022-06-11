/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:10:43 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:10:43 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_general	*gen)
{
	int	temp;

	if (gen->stack_a->length > 1)
	{
		temp = gen->stack_a->numbers[0];
		gen->stack_a->numbers[0] = gen->stack_a->numbers[1];
		gen->stack_a->numbers[1] = temp;
	}
	print_operation(gen, "sa\n");
}

void	do_sb(t_general	*gen)
{
	int	temp;

	if (gen->stack_b->length > 1)
	{
		temp = gen->stack_b->numbers[0];
		gen->stack_b->numbers[0] = gen->stack_b->numbers[1];
		gen->stack_b->numbers[1] = temp;
	}
	print_operation(gen, "sb\n");
}

void	do_ss(t_general	*gen)
{
	do_sa(gen);
	do_sb(gen);
	print_operation(gen, "ss\n");
}
