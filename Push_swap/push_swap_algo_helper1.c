/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_helper1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:47:57 by sgarba            #+#    #+#             */
/*   Updated: 2026/05/25 20:47:57 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_rrr(t_stack *a, t_stack *b, int real_a, int real_b)
{
	while (real_a > 0 && real_b > 0)
	{
		ft_rrr(a, b);
		real_a--;
		real_b--;
	}
}
void	ft_execute_combined(t_stack *a, t_stack *b, t_node *best)
{
	int	pos_a;
	int	pos_b;

	if (b->head == NULL)
		return ;
	pos_a = ft_get_position(best, a);
	pos_b = ft_get_position(ft_find_target(b, best->value), b);
	while (pos_a > 0 && pos_b > 0 && pos_a <= a->size / 2 && pos_b <= b->size / 2)
	{
		ft_rr(a, b);
		pos_a--;
		pos_b--;
	}
	if (pos_a > a->size / 2 && pos_b > b->size / 2)
		ft_do_rrr(a,b, a->size - pos_a, b->size - pos_b);
}
void	ft_execute_a(t_stack *a, t_node *best)
{
	int	pos_a;

	pos_a = ft_get_position(best, a);
	while (pos_a > 0 && pos_a <= a->size / 2)
	{
		ft_ra(a, 1);
		pos_a--;
	}
	pos_a = ft_get_position(best, a);
	while (pos_a > a->size / 2)
	{
		ft_rra(a, 1);
		pos_a = ft_get_position(best, a);
	}
}
void	ft_execute_b(t_stack *b, t_node *best)
{
	int	pos_b;

	if (b->head == NULL)
		return ;
	pos_b = ft_get_position(ft_find_target(b, best->value), b);
	while (pos_b > 0 && pos_b <= b->size / 2)
	{
		ft_rb(b, 1);
		pos_b--;
	}
	pos_b = ft_get_position(ft_find_target(b, best->value), b);
	while (pos_b > b->size / 2)
	{
		ft_rrb(b, 1);
		pos_b = ft_get_position(ft_find_target(b, best->value), b);
	}
}
void	ft_execute(t_stack *a, t_stack *b, t_node *best)
{
	ft_execute_combined(a, b, best);
	ft_execute_a(a, best);
	ft_execute_b(b, best);
	ft_pb(a, b);
}
