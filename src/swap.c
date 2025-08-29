/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:01:24 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/08/29 18:15:13 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_list **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next) || !stack_b || !*stack_b
		|| !(*stack_b)->next)
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
