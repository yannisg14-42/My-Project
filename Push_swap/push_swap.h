/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:10:29 by sgarba            #+#    #+#             */
/*   Updated: 2026/06/02 23:33:23 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_chunk
{
	int	*sorted;
	int	n;
	int	min;
	int	max;
}	t_chunk;

int	ft_is_valid_int(char *result);

int	ft_is_dup(char **str);

t_node	*ft_make_node(int value);

void	ft_populate_stack(t_stack *stack, char *argv[]);

void	ft_pa(t_stack *a, t_stack *b);

void	ft_pb(t_stack *a, t_stack *b);

void	ft_sa(t_stack *a, int print);

void	ft_sb(t_stack *b, int print);

void	ft_ss(t_stack *a, t_stack *b);

void	ft_ra(t_stack *a, int print);

void	ft_rb(t_stack *b, int print);

void	ft_rr(t_stack *a, t_stack *b);

void	ft_rra(t_stack *a, int print);

void	ft_rrb(t_stack *b, int print);

void	ft_rrr(t_stack *a, t_stack *b);

int	ft_get_position(t_node *nod, t_stack *stak);

t_node	*ft_find_target(t_stack *stak, int x);

t_node	*ft_find_min(t_stack *stak);

int	ft_get_cost(int cost_a, int cost_b, int size_a, int size_b);

void	ft_execute_combined(t_stack *a, t_stack *b, t_node *best);

void	ft_execute_a(t_stack *a, t_node *best);

void	ft_execute_b(t_stack *b, t_node *best);

void	ft_execute(t_stack *a, t_stack *b, t_node *best);

void	ft_algorithm(t_stack *a, t_stack *b);

void	ft_find_best(t_stack *a, t_stack *b, t_node **best, int *min_cost);

int	ft_validate_arg(char *argv[]);

void	ft_sort_three(t_stack *a);

void	ft_push_back(t_stack *a, t_stack *b);

void	ft_init_stack(t_stack *a, t_stack *b);

void	ft_free_all(t_stack *stak);

void	ft_run(int argc, char *argv[], t_stack *a, t_stack *b);

void	ft_do_rrr(t_stack *a, t_stack *b,  int real_a, int real_b);

void	ft_rotate_min(t_stack *a);

void	ft_rotate_a_to_target(t_stack *a, t_node *best_b);

void	ft_rotate_b_to_best(t_stack *b, t_node *best_b);

t_node	*ft_find_best_b(t_stack *a, t_stack *b, int *min_cost);

void	ft_execute_back(t_stack *a, t_stack *b, t_node *best_b);

void	ft_sort_int_arr(int	*arr, int size);

int	*ft_sorted_arr(t_stack *a);

int	ft_get_rank(int *sorted, int size, int val);

int	ft_chunk_pos(t_stack *a, t_chunk chunk);

void	ft_push_chunk(t_stack *a, t_stack *b, t_chunk chunk);

void	ft_greedy_sort(t_stack *a, t_stack *b);
#endif