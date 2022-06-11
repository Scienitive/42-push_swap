/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:10:31 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:10:45 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_2(t_general *gen)
{
	if (gen->stack_a->numbers[0] > gen->stack_a->numbers[1])
		do_sa(gen);
	print_last(gen);
}

static void	assign_lmb(t_general *gen, int *lmb)
{
	int	i;

	i = 1;
	lmb[0] = 0;
	lmb[1] = 0;
	lmb[2] = 0;
	while (i < 3)
	{
		if (gen->stack_a->numbers[i] < gen->stack_a->numbers[lmb[0]])
			lmb[0] = i;
		if (gen->stack_a->numbers[i] > gen->stack_a->numbers[lmb[2]])
			lmb[2] = i;
		i++;
	}
	lmb[1] = 3 - (lmb[2] + lmb[0]);
}

static void	cases(t_general *gen, int *lmb)
{
	if (lmb[0] == 1 && lmb[1] == 0 && lmb[2] == 2)
		do_sa(gen);
	else if (lmb[0] == 2 && lmb[1] == 1 && lmb[2] == 0)
	{
		do_sa(gen);
		do_rra(gen);
	}
	else if (lmb[0] == 1 && lmb[1] == 2 && lmb[2] == 0)
		do_ra(gen);
	else if (lmb[0] == 0 && lmb[1] == 2 && lmb[2] == 1)
	{
		do_sa(gen);
		do_ra(gen);
	}
	else if (lmb[0] == 2 && lmb[1] == 0 && lmb[2] == 1)
		do_rra(gen);
}

void	push_swap_3(t_general *gen, int is_3)
{
	int	*lmb;
	int	i;

	lmb = malloc(3 * sizeof(int));
	assign_lmb(gen, lmb);
	cases(gen, lmb);
	if (!is_3)
	{
		if (gen->length - 4)
		{
			if (gen->stack_b->numbers[0] < gen->stack_b->numbers[1])
				do_sb(gen);
		}
		i = 1;
		while (gen->length - 4 + i > 0)
		{
			do_pa(gen);
			i--;
		}
	}
	free(lmb);
	print_last(gen);
}

void	push_swap_5(t_general *gen)
{
	int	count;

	count = 0;
	while (count < gen->length - 3)
	{
		if (gen->stack_a->numbers[0] <= gen->length - 4)
		{
			do_pb(gen);
			count++;
		}
		else
			do_ra(gen);
	}
	push_swap_3(gen, 0);
}
