/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:11:02 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:11:02 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	biggest_smallest(t_general	*gen)
{
	int	biggest;
	int	smallest;
	int	i;

	biggest = 0;
	smallest = 0;
	i = 1;
	while (i < gen->stack_b->length)
	{
		if (gen->stack_b->numbers[i] > gen->stack_b->numbers[biggest])
			biggest = i;
		if (gen->stack_b->numbers[i] < gen->stack_b->numbers[smallest])
			smallest = i;
		i++;
	}
	gen->stack_b->b_index = biggest;
	gen->stack_b->s_index = smallest;
}

void	conclusion(t_general *gen, int	*sml_min_moves, int	*big_min_moves)
{
	int	i;
	int	repeat;
	int	is_ra;

	repeat = big_min_moves[0];
	is_ra = big_min_moves[1];
	if (sml_min_moves[0] <= big_min_moves[0])
	{
		repeat = sml_min_moves[0];
		is_ra = sml_min_moves[1];
	}
	i = 0;
	while (i++ < repeat)
	{
		if (is_ra)
			do_rb(gen);
		else
			do_rrb(gen);
	}
	do_pa(gen);
	if (sml_min_moves[0] <= big_min_moves[0])
		do_ra(gen);
}

void	push_to_stack_a(t_general	*gen)
{
	int	*big_min_moves;
	int	*sml_min_moves;

	biggest_smallest(gen);
	big_min_moves = malloc(2 * sizeof(int));
	sml_min_moves = malloc(2 * sizeof(int));
	big_min_moves[0] = gen->stack_b->b_index;
	big_min_moves[1] = 1;
	if (gen->stack_b->b_index > (gen->stack_b->length - gen->stack_b->b_index))
	{
		big_min_moves[0] = (gen->stack_b->length - gen->stack_b->b_index);
		big_min_moves[1] = 0;
	}
	sml_min_moves[0] = gen->stack_b->s_index;
	sml_min_moves[1] = 1;
	if (gen->stack_b->s_index > (gen->stack_b->length - gen->stack_b->s_index))
	{
		sml_min_moves[0] = (gen->stack_b->length - gen->stack_b->s_index);
		sml_min_moves[1] = 0;
	}
	conclusion(gen, sml_min_moves, big_min_moves);
	free(big_min_moves);
	free(sml_min_moves);
}
