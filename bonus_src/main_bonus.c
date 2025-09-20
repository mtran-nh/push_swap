/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:23:56 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/20 22:51:09 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	apply_operations(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(instr, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(instr, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(instr, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(instr, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(instr, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strcmp(instr, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(instr, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(instr, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(instr, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(instr, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(instr, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instr;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (++i < ac)
		append_node(&stack_a, new_node(atoi(av[i])));
	instr = get_next_line(0);
	while (instr)
	{
		if (!apply_operations(instr, &stack_a, &stack_b))
			return (write(2, "ERROR\n", 6), free(instr), free_stack(&stack_a),
				free_stack(&stack_b), 1);
		free(instr);
		instr = get_next_line(0);
	}
	if (check_sorted(&stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
