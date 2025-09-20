/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:27:02 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/19 15:04:45 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_both(t_stack **stack_a, t_stack **stack_b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(stack_a, stack_b, 1);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(stack_a, stack_b, 1);
		(*ca)++;
		(*cb)++;
	}
}

static void	rotate_a(t_stack **stack_a, int *ca)
{
	while (*ca > 0)
	{
		ra(stack_a, 1);
		(*ca)--;
	}
	while (*ca < 0)
	{
		rra(stack_a, 1);
		(*ca)++;
	}
}

static void	rotate_b(t_stack **stack_b, int *cb)
{
	while (*cb > 0)
	{
		rb(stack_b, 1);
		(*cb)--;
	}
	while (*cb < 0)
	{
		rrb(stack_b, 1);
		(*cb)++;
	}
}

void	apply_rotation(t_stack **stack_a, t_stack **stack_b, int *ca, int *cb)
{
	rotate_both(stack_a, stack_b, ca, cb);
	rotate_a(stack_a, ca);
	rotate_b(stack_b, cb);
}

void	move_nodes(t_stack **stack_a, t_stack **stack_b)
{
	int	costs[2];

	return_cheapest(*stack_a, *stack_b, costs);
	apply_rotation(stack_a, stack_b, &costs[0], &costs[1]);
	pa(stack_a, stack_b, 1);
}
