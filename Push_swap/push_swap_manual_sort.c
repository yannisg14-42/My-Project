/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_manual_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:48:14 by sgarba            #+#    #+#             */
/*   Updated: 2026/05/25 20:48:14 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *a)
{
	int		x;
	int		y;
	int		z;

	x = a->head->value;
	y = a->head->next->value;
	z = a->tail->value;
	if (x < y && y < z)
		return ;
	else if (x < y && y > z && x < z)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
	else if (x > y && x < z)
		ft_sa(a, 1);
	else if (x < y && x > z)
		ft_rra(a, 1);
	else if (x > z && y < z)
		ft_ra(a, 1);
	else if (x > y && y > z)
	{
		ft_sa(a, 1);
		ft_rra(a, 1);
	}
}

void	ft_push_back(t_stack *a, t_stack *b)
{
	t_node	*best;
	int		min_cost;

	while (b->head != NULL)
	{
		min_cost = INT_MAX;
		best = ft_find_best_b(a, b, &min_cost);
		ft_execute_back(a, b, best);
	}
}

void	ft_execute_back(t_stack *a, t_stack *b, t_node *best_b)
{
	int	pos_b;
	int	pos_a;

	pos_b = ft_get_position(best_b, b);
	pos_a = ft_get_position(ft_find_target(a, best_b->value), a);
	while (pos_b > 0 && pos_a > 0 && 
		pos_b <= b->size / 2 && pos_a <= a->size / 2)
	{
		ft_rr(a, b);
		pos_b--;
		pos_a--;
	}
	if (pos_b > b->size / 2 && pos_a > a->size / 2)
		ft_do_rrr(a, b, b->size - pos_b, a->size - pos_a);
	ft_rotate_b_to_best(b, best_b);
	ft_rotate_a_to_target(a, best_b);
	ft_pa(a, b);
}

void	ft_rotate_b_to_best(t_stack *b, t_node *best_b)
{
	int	pos_b;

	pos_b = ft_get_position(best_b, b);
	while (pos_b > 0 && pos_b <= b->size / 2)
	{
		ft_rb(b, 1);
		pos_b--;
	}
	while (pos_b > b->size / 2)
	{
		ft_rrb(b, 1);
		pos_b = ft_get_position(best_b, b);
	}
}

void	ft_rotate_a_to_target(t_stack *a, t_node *best_b)
{
	int	pos_a;

	pos_a = ft_get_position(ft_find_target(a, best_b->value), a);
	while (pos_a > 0 && pos_a <= a->size / 2)
	{
		ft_ra(a, 1);
		pos_a--;
	}
	while (pos_a > a->size / 2)
	{
		ft_rra(a, 1);
		pos_a = ft_get_position(ft_find_target(a, best_b->value), a);
	}
}
