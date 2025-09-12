/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:47:45 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/12 21:54:35 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int		max;
	t_stack	*tmp;
	int		bits;

	max = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

static void	rotate_top(t_stack **stack, int pos, int print)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack, print);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack, print);
	}
}

static void	final_rotate(t_stack **stack_a)
{
	t_stack	*tmp;
	int		pos;
	int		min_pos;
	int		min_index;

	tmp = *stack_a;
	pos = 0;
	min_pos = 0;
	min_index = tmp->index;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	rotate_top(stack_a, min_pos, 1);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	bit;
	int	i;
	int	size;
	int	max_bits;

	max_bits = get_max_bits(*stack_a);
	bit = -1;
	while (++bit < max_bits)
	{
		size = stack_size(*stack_a);
		i = 0;
		while (i++ < size)
		{
			if (((*stack_a)->index >> bit) & 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b, 1);
		}
		while (*stack_b)
			pa(stack_a, stack_b, 1);
	}
	final_rotate(stack_a);
}

// void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
// {
// 	int	i;
// 	int	j;
// 	int	max_bits;

// 	max_bits = get_max_bits(*stack_a);
// 	i = -1;
// 	while (++i < max_bits)
// 	{
// 		j = -1;
// 		while (++j < size)
// 		{
// 			if (((*stack_a)->index >> i) & 1)
// 				ra(stack_a, 1);
// 			else
// 				pb(stack_a, stack_b, 1);
// 		}
// 		while (*stack_b)
// 			pa(stack_a, stack_b, 1);
// 	}
// }
