/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:31:27 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/08/29 18:14:54 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_dup(t_list *stack)
{
	t_list	*check;
	t_list	*now;

	now = stack;
	while (now)
	{
		check = now->next;
		while (check)
		{
			if (now->content == check->content)
				return (1);
			check = check->next;
		}
		now = now->next;
	}
	return (0);
}

char	*create_input(char **argv)
{
	int		i;
	char	*input;
	char	*temp;

	i = 0;
	input = ft_strdup("");
	if (!input)
		return (NULL);
	while (argv[++i])
	{
		temp = input;
		input = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!input)
			return (NULL);
		if (argv[i + 1])
		{
			temp = input;
			input = ft_strjoin(temp, " ");
			free(temp);
			if (!input)
				return (NULL);
		}
	}
	return (input);
}

static int	valid_num(char *s)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	if (!s[i])
		return (0);
	num = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		num = num * 10 + (s[i] - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char *input, t_list **stack_a)
{
	int		i;
	char	**nums;
	long	value;

	if (!input)
		return (0);
	nums = ft_split(input, ' ');
	if (!nums)
		return (0);
	i = -1;
	while (nums[++i])
	{
		if (!valid_num(nums[i]))
			return (free_arr(nums), 0);
		value = ft_atol(nums[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (free_arr(nums), 0);
		if (!append_node(stack_a, new_node((int)value)))
			return (free_arr(nums), (stack_a), 0);
	}
	free_arr(nums);
	if (check_dup(*stack_a))
		return (free(stack_a), 0);
	return (1);
}
