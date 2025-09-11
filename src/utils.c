/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:53:13 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/11 13:52:55 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int n)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	append_node(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !new)
		return (0);
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
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	set_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*other;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		other = stack;
		while (other)
		{
			if (current->index > other->index)
				index++;
			other = other->next;
		}
		current->index = index;
		current = current->next;
	}
}
