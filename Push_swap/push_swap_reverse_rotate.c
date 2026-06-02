/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:48:17 by sgarba            #+#    #+#             */
/*   Updated: 2026/05/25 20:48:17 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, int print)
{
	t_node	*tmp;

	if (a->head == NULL || a->head == a->tail)
		return ;
	tmp = a->tail;
	a->tail = tmp->prev;
	a->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = a->head;
	a->head->prev = tmp;
	a->head = tmp;
	if (print == 1)
		write(1, "rra\n", 4);
}
void	ft_rrb(t_stack *b, int print)
{
	t_node	*tmp;

	if (b->head == NULL || b->head == b->tail)
		return ;
	tmp = b->tail;
	b->tail = tmp->prev;
	b->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = b->head;
	b->head->prev = tmp;
	b->head = tmp;
	if (print == 1)
		write(1, "rrb\n", 4);
}
void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	write(1, "rrr\n", 4);
}