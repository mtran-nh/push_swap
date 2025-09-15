/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:51:17 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/15 19:14:36 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Tìm vị trí gần nhất của phần tử trong chunk [min,max] */
static int	find_pos_chunk(t_stack *stack, int min, int max)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

/* Tìm vị trí lớn nhất trong B */
static int	find_max_pos(t_stack *stack)
{
	int	max;
	int	pos;
	int	max_pos;

	max = stack->index;
	pos = 0;
	max_pos = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

/* Đẩy các phần tử trong chunk từ A sang B */
static void	push_chunk_to_b(t_stack **a, t_stack **b, int min, int max)
{
	int	pos;

	while ((pos = find_pos_chunk(*a, min, max)) != -1)
	{
		if (pos <= stack_size(*a) / 2)
			while (pos-- > 0)
				ra(a, 1);
		else
		{
			pos = stack_size(*a) - pos;
			while (pos-- > 0)
				rra(a, 1);
		}
		pb(a, b, 1);
	}
}

/* Merge B → A theo phần tử lớn nhất lên top */
static void	merge_b_to_a(t_stack **a, t_stack **b)
{
	int	max_pos;

	while (*b)
	{
		max_pos = find_max_pos(*b);
		if (max_pos <= stack_size(*b) / 2)
			while (max_pos-- > 0)
				rb(b, 1);
		else
		{
			max_pos = stack_size(*b) - max_pos;
			while (max_pos-- > 0)
				rrb(b, 1);
		}
		pa(a, b, 1);
	}
}

/* --- Chunk sort chắc chắn --- */
void	chunk_sort(t_stack **a, t_stack **b, int chunk_count)
{
	int size = stack_size(*a);
	int chunk_size = size / chunk_count;
	int i, min, max;

	for (i = 0; i < chunk_count; i++)
	{
		min = i * chunk_size;
		max = (i == chunk_count - 1) ? size - 1 : (i + 1) * chunk_size - 1;
		push_chunk_to_b(a, b, min, max);
	}

	merge_b_to_a(a, b);
}