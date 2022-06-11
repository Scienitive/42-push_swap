/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:03:17 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/08 14:10:50 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int	*numbers;
	int	length;
	int	s_index;
	int	b_index;
}	t_stack;

typedef struct s_general
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		length;
	char	*o1;
	char	*o2;
}	t_general;

int		check_input(char **argv, int argv_plus);
void	initialize(char **argv, t_general *gen, int argv_plus);
void	init_stacks(t_general *gen);
void	push_to_stack_b(t_general *gen, int divider, int rotation);
void	push_to_stack_a(t_general *gen);
void	final_touch(t_general *gen);
void	print_stack(t_general *gen, const char stack);
void	print_stacks(t_general *gen);
void	print_operation(t_general *gen, char *str);
void	print_last(t_general *gen);
void	push_swap_advanced(t_general *gen, int divider);
void	free_everything(t_general *gen);
void	push_swap_2(t_general *gen);
void	push_swap_3(t_general *gen, int is_3);
void	push_swap_5(t_general *gen);
int		is_it_sorted(t_general *gen);
int		*copy_array(int *arr, int arr_len);
long	ft_atol(const char *str);

void	do_pb(t_general	*gen);
void	do_pa(t_general	*gen);
void	do_sa(t_general	*gen);
void	do_sb(t_general	*gen);
void	do_ss(t_general	*gen);
void	do_ra(t_general	*gen);
void	do_rb(t_general	*gen);
void	do_rr(t_general	*gen);
void	do_rra(t_general *gen);
void	do_rrb(t_general *gen);
void	do_rrr(t_general *gen);

#endif