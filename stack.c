/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:53:13 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/08/14 10:41:14 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int n)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	append_node(t_list **stack, t_list *new)
{
	t_list	*temp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	new->next = NULL;
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
