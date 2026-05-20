/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:10:29 by sgarba            #+#    #+#             */
/*   Updated: 2026/05/19 21:41:59 by marvin           ###   ########.fr       */
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

#endif