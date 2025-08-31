/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:53:13 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/08/31 00:41:22 by mtran-nh         ###   ########.fr       */
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

int	append_node(t_list **stack, t_list *new)
{
	t_list	*temp;

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

void	set_index(t_list *stack, int size)
{
	t_list	*current;
	t_list	*other;
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
