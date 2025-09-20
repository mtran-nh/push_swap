/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:00:36 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/20 21:58:52 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack				*new_node(int n);
int					append_node(t_stack **stack, t_stack *new);
void				free_stack(t_stack **stack);
void				free_arr(char **arr);
void				set_index(t_stack *stack);

void				sa(t_stack **stack_a, int print);
void				sb(t_stack **stack_b, int print);
void				ss(t_stack **stack_a, t_stack **stack_b, int print);
void				pa(t_stack **stack_a, t_stack **stack_b, int print);
void				pb(t_stack **stack_a, t_stack **stack_b, int print);
void				ra(t_stack **stack_a, int print);
void				rb(t_stack **stack_b, int print);
void				rr(t_stack **stack_a, t_stack **stack_b, int print);
void				rra(t_stack **stack_a, int print);
void				rrb(t_stack **stack_b, int print);
void				rrr(t_stack **stack_a, t_stack **stack_b, int print);

int					check_dup(t_stack *stack);
char				*create_input(char **argv);
int					check_input(char *input, t_stack **stack_a);

int					stack_size(t_stack *stack);
void				three_elements(t_stack **stack_a);
void				four_five_elements(t_stack **stack_a, t_stack **stack_b,
						int nums);
int					check_sorted(t_stack **stack_a);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);

void				push_swap(t_stack **stack_a, t_stack **stack_b);
int					get_pos(t_stack *stack, t_stack *node);
int					is_above_median(t_stack *stack, t_stack *node);
t_stack				*find_smallest(t_stack *stack);

void				apply_rotation(t_stack **stack_a, t_stack **stack_b,
						int *ca, int *cb);
void				move_nodes(t_stack **stack_a, t_stack **stack_b);
void				return_cheapest(t_stack *stack_a, t_stack *stack_b,
						int *out_costs);

int					main(int ac, char **av);

char				*get_next_line(int fd);

#endif