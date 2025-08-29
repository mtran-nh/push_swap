/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:28:05 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/08/14 10:39:17 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*temp;

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

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b || !*stack_b)
		return ;
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b || !stack_a || !*stack_a)
		return ;
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
