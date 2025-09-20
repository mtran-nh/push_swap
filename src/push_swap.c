/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:01:36 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/19 15:10:38 by mtran-nh         ###   ########.fr       */
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

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;

	if (stack_size(*stack_a) == 5)
		four_five_elements(stack_a, stack_b, 5);
	else
		while (stack_size(*stack_a) > 3)
			pb(stack_a, stack_b, 1);
	three_elements(stack_a);
	while (*stack_b)
		move_nodes(stack_a, stack_b);
	smallest = find_smallest(*stack_a);
	if (is_above_median(*stack_a, smallest))
		while (*stack_a != smallest)
			ra(stack_a, 1);
	else
		while (*stack_a != smallest)
			rra(stack_a, 1);
}
