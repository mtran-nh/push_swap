/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:27:02 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/18 19:27:22 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b, 1);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b, 1);
		(*ca)++;
		(*cb)++;
	}
}

static void	rotate_a(t_stack **a, int *ca)
{
	while (*ca > 0)
	{
		ra(a, 1);
		(*ca)--;
	}
	while (*ca < 0)
	{
		rra(a, 1);
		(*ca)++;
	}
}

static void	rotate_b(t_stack **b, int *cb)
{
	while (*cb > 0)
	{
		rb(b, 1);
		(*cb)--;
	}
	while (*cb < 0)
	{
		rrb(b, 1);
		(*cb)++;
	}
}

void	apply_rotation(t_stack **a, t_stack **b, int *ca, int *cb)
{
	rotate_both(a, b, ca, cb);
	rotate_a(a, ca);
	rotate_b(b, cb);
}


void	move_nodes(t_stack **a, t_stack **b)
{
	int	costs[2];

	return_cheapest(*a, *b, costs);
	apply_rotation(a, b, &costs[0], &costs[1]);
	pa(a, b, 1);
}
