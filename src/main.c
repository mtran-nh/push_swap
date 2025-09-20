/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:28:00 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/19 14:57:53 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*input;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	input = create_input(av);
	if (!check_input(input, &stack_a))
	{
		free(input);
		write(1, "Invalid input\n", 15);
		return (1);
	}
	free(input);
	set_index(stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
