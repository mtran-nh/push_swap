/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 00:07:56 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/18 19:04:46 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	three_elements(t_stack **stack_a)
{
	int	x;
	int	y;
	int	z;

	x = (*stack_a)->index;
	y = (*stack_a)->next->index;
	z = (*stack_a)->next->next->index;
	if (x < y && y > z && z > x)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (x > y && y < z && z > x)
		sa(stack_a, 1);
	else if (x < y && y > z && z < x)
		rra(stack_a, 1);
	else if (x > y && y > z && z < x)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (x > y && y < z && z < x)
		ra(stack_a, 1);
}

void	four_five_elements(t_stack **stack_a, t_stack **stack_b, int nums)
{
	int	push_b;

	push_b = nums - 3;
	while (push_b > 0)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			pb(stack_a, stack_b, 1);
			push_b--;
		}
		else
			ra(stack_a, 1);
	}
	if (nums == 5 && (*stack_b)->index < (*stack_b)->next->index)
		sb(stack_b, 1);
	three_elements(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}

int	check_sorted(t_stack **stack_a)
{
	t_stack	*head;

	head = (*stack_a);
	while (head && head->next)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = stack_size(*stack_a);
	if (check_sorted (stack_a))
		return ;
	if (size == 1)
		return ;
	if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, 1);
	}
	else if (size == 3)
		three_elements(stack_a);
	else if (size == 4 || size == 5)
		four_five_elements(stack_a, stack_b, size);
	else
	{
		push_swap(stack_a, stack_b);
	}
}
