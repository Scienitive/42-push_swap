/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_touch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:10:17 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:10:18 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_touch(t_general	*gen)
{
	int	i;
	int	repeat;

	i = 0;
	if (gen->stack_a->numbers[0]
		< (gen->stack_a->length - gen->stack_a->numbers[0]))
	{
		repeat = gen->stack_a->numbers[0];
		while (i++ < repeat)
		{
			do_rra(gen);
		}
	}
	else
	{
		repeat = gen->stack_a->length - gen->stack_a->numbers[0];
		while (i++ < repeat)
			do_ra(gen);
	}
	if (gen->o1[0] != '\0')
		ft_putstr_fd(gen->o1, 1);
	if (gen->o2[0] != '\0')
		ft_putstr_fd(gen->o2, 1);
}
