/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:10:28 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:10:28 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_general	*gen)
{
	int	temp;
	int	i;

	if (gen->stack_a->length > 1)
	{
		i = 0;
		temp = gen->stack_a->numbers[i];
		while (i < gen->stack_a->length - 1)
		{
			gen->stack_a->numbers[i] = gen->stack_a->numbers[i + 1];
			i++;
		}
		gen->stack_a->numbers[gen->stack_a->length - 1] = temp;
	}
	print_operation(gen, "ra\n");
}

void	do_rb(t_general	*gen)
{
	int	temp;
	int	i;

	if (gen->stack_b->length > 1)
	{
		i = 0;
		temp = gen->stack_b->numbers[i];
		while (i < gen->stack_b->length - 1)
		{
			gen->stack_b->numbers[i] = gen->stack_b->numbers[i + 1];
			i++;
		}
		gen->stack_b->numbers[gen->stack_b->length - 1] = temp;
	}
	print_operation(gen, "rb\n");
}

void	do_rr(t_general	*gen)
{
	do_ra(gen);
	do_rb(gen);
	print_operation(gen, "rr\n");
}
