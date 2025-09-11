/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:28:05 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/11 13:33:56 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*temp;

	temp = *stack_2;
	*stack_2 = temp->next;
	if (*stack_2)
		(*stack_2)->prev = NULL;
	temp->next = *stack_1;
	if (*stack_1)
		(*stack_1)->prev = temp;
	temp->prev = NULL;
	*stack_1 = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (!stack_a || !stack_b || !*stack_b)
		return ;
	push(stack_a, stack_b);
	if (print == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (!stack_b || !stack_a || !*stack_a)
		return ;
	push(stack_b, stack_a);
	if (print == 1)
		write(1, "pb\n", 3);
}
