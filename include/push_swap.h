/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:00:36 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/08/31 19:25:54 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list				*new_node(int n);
int					append_node(t_list **stack, t_list *new);
void				free_stack(t_list **stack);
void				free_arr(char **arr);
void				set_index(t_list *stack, int size);

void				sa(t_list **stack_a, int print);
void				sb(t_list **stack_b, int print);
void				pa(t_list **stack_a, t_list **stack_b, int print);
void				pb(t_list **stack_a, t_list **stack_b, int print);
void				ra(t_list **stack_a, int print);
void				rb(t_list **stack_b, int print);
void				rr(t_list **stack_a, t_list **stack_b, int print);
void				rra(t_list **stack_a, int print);
void				rrb(t_list **stack_b, int print);
void				rrr(t_list **stack_a, t_list **stack_b, int print);

int					check_dup(t_list *stack);
char				*create_input(char **argv);
int					check_input(char *input, t_list **stack_a);


int					stack_size(t_list *stack);
void				radix_sort(t_list **stack_a, t_list **stack_b, int size);
void				three_elements(t_list **stack_a);
void				four_five_elements(t_list **stack_a, t_list **stack_b,
						int nums);
int					check_sorted(t_list **stack_a);
void				sort_stack(t_list **stack_a, t_list **stack_b);

#endif