/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:47:45 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/13 14:53:32 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include "push_swap.h"

/* Tìm vị trí gần nhất của phần tử trong chunk [min,max] */
static int find_pos_chunk(t_stack *stack, int min, int max)
{
    int pos = 0;
    while(stack)
    {
        if(stack->index >= min && stack->index <= max)
            return pos;
        stack = stack->next;
        pos++;
    }
    return -1;
}

/* Tìm vị trí lớn nhất trong B */
static int find_max_pos(t_stack *stack)
{
    int max = stack->index;
    int pos = 0;
    int max_pos = 0;

    while(stack)
    {
        if(stack->index > max)
        {
            max = stack->index;
            max_pos = pos;
        }
        stack = stack->next;
        pos++;
    }
    return max_pos;
}

/* Đẩy các phần tử trong chunk từ A sang B */
static void push_chunk_to_b(t_stack **a, t_stack **b, int min, int max)
{
    int pos;
    while((pos = find_pos_chunk(*a,min,max)) != -1)
    {
        if(pos <= stack_size(*a)/2)
            while(pos-- >0) ra(a,1);
        else
        {
            pos = stack_size(*a)-pos;
            while(pos-- >0) rra(a,1);
        }
        pb(a,b,1);
    }
}

/* Merge B → A theo phần tử lớn nhất lên top */
static void merge_b_to_a(t_stack **a, t_stack **b)
{
    int max_pos;
    while(*b)
    {
        max_pos = find_max_pos(*b);
        if(max_pos <= stack_size(*b)/2)
            while(max_pos-- >0) rb(b,1);
        else
        {
            max_pos = stack_size(*b)-max_pos;
            while(max_pos-- >0) rrb(b,1);
        }
        pa(a,b,1);
    }
}

/* --- Chunk sort chắc chắn --- */
void radix_sort(t_stack **a, t_stack **b, int chunk_count)
{
    int size = stack_size(*a);
    int chunk_size = size / chunk_count;
    int i, min, max;

    for(i=0;i<chunk_count;i++)
    {
        min = i*chunk_size;
        max = (i==chunk_count-1)? size-1 : (i+1)*chunk_size-1;
        push_chunk_to_b(a,b,min,max);
    }

    merge_b_to_a(a,b);
}



// static int	get_max_bits(t_stack *stack)
// {
// 	int		max;
// 	t_stack	*tmp;
// 	int		bits;

// 	max = 0;
// 	tmp = stack;
// 	while (tmp)
// 	{
// 		if (tmp->index > max)
// 			max = tmp->index;
// 		tmp = tmp->next;
// 	}
// 	bits = 0;
// 	while (max >> bits)
// 		bits++;
// 	return (bits);
// }

// static void	final_rotate(t_stack **stack_a)
// {
// 	t_stack	*tmp;
// 	int		pos;
// 	int		min_pos;
// 	int		min_index;

// 	tmp = *stack_a;
// 	pos = 0;
// 	min_pos = 0;
// 	min_index = tmp->index;
// 	while (tmp)
// 	{
// 		if (tmp->index < min_index)
// 		{
// 			min_index = tmp->index;
// 			min_pos = pos;
// 		}
// 		tmp = tmp->next;
// 		pos++;
// 	}
// 	if (min_pos <= stack_size(*stack_a) / 2)
// 	{
// 		while (min_pos-- > 0)
// 			ra(stack_a, 1);
// 	}
// 	else
// 	{
// 		min_pos = stack_size(*stack_a) - min_pos;
// 		while (min_pos-- > 0)
// 			rra(stack_a, 1);
// 	}
// }

// static void	push_bit_zero(t_stack **a, t_stack **b, int bit)
// {
// 	int	size;
// 	int	i;

// 	size = stack_size(*a);
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (((*a)->index >> bit) & 1)
// 			ra(a, 1);
// 		else
// 			pb(a, b, 1);
// 		i++;
// 	}
// }

// static void	push_bit_one(t_stack **a, t_stack **b, int bit)
// {
// 	int	size;
// 	int	i;

// 	size = stack_size(*b);
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (((*b)->index >> bit) & 1)
// 			pa(a, b, 1);
// 		else
// 			rb(b, 1);
// 		i++;
// 	}
// }

// void	radix_sort(t_stack **a, t_stack **b)
// {
// 	int	max_bits;
// 	int	bit;

// 	max_bits = get_max_bits(*a);
// 	bit = 0;
// 	while (bit < max_bits)
// 	{
// 		push_bit_zero(a, b, bit);
// 		push_bit_one(a, b, bit + 1);
// 		bit++;
// 	}
// 	while (*b)
// 		pa(a, b, 1);
// 	final_rotate(a);
// }

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
