/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:11:06 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:11:07 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_splitters(t_general *gen, int *min_max, int div, int rot)
{
	min_max[0] = (gen->length - (gen->length / div))
		- (rot * (gen->length / div));
	if ((rot + 1) - (div - (gen->length % div)) > 0)
		min_max[0] -= (rot + 1) - (div - (gen->length % div));
	min_max[1] = (gen->length - 1) - (rot * (gen->length / div));
	if (rot - (div - (gen->length % div)) > 0)
		min_max[1] -= rot - (div - (gen->length % div));
}

void	push_to_stack_b(t_general *gen, int divider, int rotation)
{
	int	*min_max;
	int	count;

	min_max = malloc(2 * sizeof(int));
	set_splitters(gen, min_max, divider, rotation);
	count = 0;
	while (count < (min_max[1] - min_max[0]) + 1)
	{
		if (gen->stack_a->numbers[0] >= min_max[0]
			&& gen->stack_a->numbers[0] <= min_max[1])
		{
			do_pb(gen);
			count++;
		}
		else
			do_ra(gen);
	}
	free(min_max);
}
