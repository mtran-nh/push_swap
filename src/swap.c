/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:01:24 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/19 15:18:29 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **stack_a, int print)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	swap(stack_a);
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int print)
{
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	swap(stack_b);
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next) || !stack_b || !*stack_b
		|| !(*stack_b)->next)
		return ;
	swap(stack_a);
	swap(stack_b);
	if (print == 1)
		write(1, "ss\n", 3);
}
