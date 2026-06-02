/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:47:59 by sgarba            #+#    #+#             */
/*   Updated: 2026/05/25 20:47:59 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_min(t_stack *a)
{
	t_node	*min;
	int		pos;

	min = ft_find_min(a);
	pos = ft_get_position(min, a);
	if (pos <= a->size / 2)
		while (a->head != min)
			ft_ra(a, 1);
	else
		while (a->head != min)
			ft_rra(a, 1);
}

void	ft_find_best(t_stack *a, t_stack *b, t_node **best, int *min_cost)
{
	int		cost;
	t_node	*current;

	current = a->head;
	cost = 0;
	while (current != NULL)
	{
		if (b->head == NULL)
			cost = ft_get_position(current, a);
		else
			cost = ft_get_cost(ft_get_position(current, a), 
					ft_get_position(ft_find_target(b, current->value), b), 
					a->size, b->size);
		if (*best == NULL || cost < *min_cost)
		{
			*best = current;
			*min_cost = cost;
		}
		current = current->next;
	}
}

void	ft_algorithm(t_stack *a, t_stack *b)
{
	int		*sorted;
	int		n;
	int		c;
	t_chunk	chunk;

	if (a->size < 7)
	{
		ft_greedy_sort(a, b);
		return ;
	}
	n = a->size;
	c = n / 3;
	sorted = ft_sorted_arr(a);
	if (!sorted)
		return ;
	chunk = (t_chunk){sorted, n, 0, c};
	ft_push_chunk(a, b, chunk);
	chunk = (t_chunk){sorted, n, c, 2 * c};
	ft_push_chunk(a, b, chunk);
	chunk = (t_chunk){sorted, n, 2 * c, n - 3};
	ft_push_chunk(a, b, chunk);
	free(sorted);
	ft_sort_three(a);
	ft_push_back(a, b);
	ft_rotate_min(a);
}

t_node	*ft_find_best_b(t_stack *a, t_stack *b, int *min_cost)
{
	t_node	*current;
	t_node	*best;
	int		cost;

	current = b->head;
	best = NULL;
	while (current != NULL)
	{
		cost = ft_get_cost(ft_get_position(current, b), 
				ft_get_position(ft_find_target(a, current->value), a), 
				b->size, a->size);
		if (best == NULL || cost < *min_cost)
		{
			best = current;
			*min_cost = cost;
		}
		current = current->next;
	}
	return (best);
}

void	ft_greedy_sort(t_stack *a, t_stack *b)
{
	t_node	*best;
	int		min_cost;

	while (a->size > 3)
	{
		best = NULL;
		min_cost = INT_MAX;
		ft_find_best(a, b, &best, &min_cost);
		ft_execute(a, b, best);
	}
	ft_sort_three(a);
	ft_push_back(a, b);
	ft_rotate_min(a);
}
