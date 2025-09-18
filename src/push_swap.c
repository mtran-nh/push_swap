/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:01:36 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/18 19:27:35 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_pos(t_stack *stack, t_stack *node)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == node)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

int	is_above_median(t_stack *stack, t_stack *node)
{
	int		pos;
	int		size;
	t_stack	*tmp;

	pos = get_pos(stack, node);
	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (pos <= size / 2);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	if (stack_size(*a) == 5)
		four_five_elements(a, b, 5);
	else
		while (stack_size(*a) > 3)
			pb(a, b, 1);
	three_elements(a);
	while (*b)
		move_nodes(a, b);
	smallest = find_smallest(*a);
	if (is_above_median(*a, smallest))
		while (*a != smallest)
			ra(a, 1);
	else
		while (*a != smallest)
			rra(a, 1);
}
