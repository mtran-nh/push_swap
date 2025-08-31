/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:43:44 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/08/31 00:52:58 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
}

void	ra(t_list **stack_a, int print)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	rotate(stack_a);
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int print)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotate(stack_b);
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int print)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next) || (!stack_b || !*stack_b
			|| !(*stack_b)->next))
		return ;
	rotate(stack_a);
	rotate(stack_b);
	if (print == 1)
		write(1, "rr\n", 3);
}
