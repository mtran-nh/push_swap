/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:47:45 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/15 19:14:28 by mtran-nh         ###   ########.fr       */
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
	if (min_pos <= stack_size(*stack_a) / 2)
	{
		while (min_pos-- > 0)
			ra(stack_a, 1);
	}
	else
	{
		min_pos = stack_size(*stack_a) - min_pos;
		while (min_pos-- > 0)
			rra(stack_a, 1);
	}
}

static void	push_bit_zero(t_stack **a, t_stack **b, int bit)
{
	int	size;
	int	i;

	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a, 1);
		else
			pb(a, b, 1);
		i++;
	}
}

static void	push_bit_one(t_stack **a, t_stack **b, int bit)
{
	int	size;
	int	i;

	size = stack_size(*b);
	i = 0;
	while (i < size)
	{
		if (((*b)->index >> bit) & 1)
			pa(a, b, 1);
		else
			rb(b, 1);
		i++;
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	bit;

	max_bits = get_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		push_bit_zero(a, b, bit);
		push_bit_one(a, b, bit + 1);
		bit++;
	}
	while (*b)
		pa(a, b, 1);
	final_rotate(a);
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
