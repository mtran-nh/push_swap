/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:38:07 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/11 13:35:26 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*temp;

	first = *stack;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->next = first;
	first->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

void	rra(t_stack **stack_a, int print)
{
	if (!stack_a || !(*stack_a))
		return ;
	reverse_rotate(stack_a);
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int print)
{
	if (!stack_b || !(*stack_b))
		return ;
	reverse_rotate(stack_b);
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (!stack_a || !(*stack_a) || !stack_b || !(*stack_b))
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print == 1)
		write(1, "rrr\n", 4);
}
