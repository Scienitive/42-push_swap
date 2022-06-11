/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:11:22 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:19:01 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_everything(t_general	*gen)
{
	free(gen->stack_a->numbers);
	free(gen->stack_b->numbers);
	free(gen->stack_a);
	free(gen->stack_b);
	free(gen->o1);
	free(gen->o2);
}

static int	operation_checker_tml(t_general	*gen, char	*str1, char	*str2)
{
	ft_putstr_fd(str1, 1);
	ft_strlcpy(gen->o1, str2, ft_strlen(str2) + 1);
	gen->o2[0] = '\0';
	return (1);
}

static int	operation_checker(t_general	*gen, char	*str)
{
	if ((ft_strncmp(gen->o1, "sa\n", 5) == 0
			&& ft_strncmp(gen->o2, "sb\n", 5) == 0)
		|| (ft_strncmp(gen->o1, "sb\n", 5) == 0
			&& ft_strncmp(gen->o2, "sa\n", 5) == 0))
		return (operation_checker_tml(gen, "ss\n", str));
	else if ((ft_strncmp(gen->o1, "ra\n", 5) == 0
			&& ft_strncmp(gen->o2, "rb\n", 5) == 0)
		|| (ft_strncmp(gen->o1, "rb\n", 5) == 0
			&& ft_strncmp(gen->o2, "ra\n", 5) == 0))
		return (operation_checker_tml(gen, "rr\n", str));
	else if ((ft_strncmp(gen->o1, "rra\n", 5) == 0
			&& ft_strncmp(gen->o2, "rrb\n", 5) == 0)
		|| (ft_strncmp(gen->o1, "rrb\n", 5) == 0
			&& ft_strncmp(gen->o2, "rra\n", 5) == 0))
		return (operation_checker_tml(gen, "rrr\n", str));
	return (0);
}

void	print_operation(t_general	*gen, char	*str)
{
	int	operation_check;

	if (gen->o1[0] == '\0')
		ft_strlcpy(gen->o1, str, ft_strlen(str) + 1);
	else if (gen->o2[0] == '\0')
		ft_strlcpy(gen->o2, str, ft_strlen(str) + 1);
	else
	{
		operation_check = operation_checker(gen, str);
		if (!operation_check)
		{
			ft_putstr_fd(gen->o1, 1);
			ft_strlcpy(gen->o1, gen->o2, ft_strlen(gen->o2) + 1);
			ft_strlcpy(gen->o2, str, ft_strlen(str) + 1);
		}
	}
}

void	print_last(t_general *gen)
{
	if (gen->o1[0] != '\0')
		ft_putstr_fd(gen->o1, 1);
	if (gen->o2[0] != '\0')
		ft_putstr_fd(gen->o2, 1);
}
