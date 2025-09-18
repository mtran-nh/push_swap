/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:25:57 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/18 19:26:17 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*get_target_node(t_stack *a, t_stack *b_node)
{
	t_stack	*target;
	long	best_match;
	t_stack	*tmp;

	target = NULL;
	best_match = LONG_MAX;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > b_node->index && tmp->index < best_match)
		{
			best_match = tmp->index;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (!target)
		target = find_smallest(a);
	return (target);
}

static void	calc_costs(t_stack *a, t_stack *b, t_stack *node, int *costs)
{
	t_stack	*target;
	int		pos_a;
	int		pos_b;
	int		size_a;
	int		size_b;

	target = get_target_node(a, node);
	pos_a = get_pos(a, target);
	pos_b = get_pos(b, node);
	size_a = stack_size(a);
	size_b = stack_size(b);
	if (pos_a <= size_a / 2)
		costs[0] = pos_a;
	else
		costs[0] = pos_a - size_a;
	if (pos_b <= size_b / 2)
		costs[1] = pos_b;
	else
		costs[1] = pos_b - size_b;
}

void	return_cheapest(t_stack *a, t_stack *b, int *out_costs)
{
	long	min_cost;
	t_stack	*tmp;
	int		tmp_costs[2];
	long	total;

	min_cost = LONG_MAX;
	tmp = b;
	while (tmp)
	{
		calc_costs(a, b, tmp, tmp_costs);
		total = labs(tmp_costs[0]) + labs(tmp_costs[1]);
		if (total < min_cost)
		{
			min_cost = total;
			out_costs[0] = tmp_costs[0];
			out_costs[1] = tmp_costs[1];
		}
		tmp = tmp->next;
	}
}

