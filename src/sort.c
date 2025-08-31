/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 00:07:56 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/08/31 01:03:37 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three_elements(t_list **stack_a)
{
	int x;
	int y;
	int z;

	x = (*stack_a)->index;
	y = (*stack_a)->next->index;
	z = (*stack_a)->next->next->index;

	if (x < y && y > z && z > x) //132
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (x > y && y < z && z > x) //213
		sa(stack_a, 1);
	else if (x < y && y > z && z < x) //231
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if () //321
}