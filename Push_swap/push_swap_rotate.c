/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:48:19 by sgarba            #+#    #+#             */
/*   Updated: 2026/05/25 20:48:19 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, int print)
{
	t_node	*tmp;

	if (a->head == NULL || a->head == a->tail)
		return ;
	tmp = a->head;
	a->head = tmp->next;
	a->head->prev = NULL;
	a->tail->next = tmp;
	tmp->prev = a->tail;
	tmp->next = NULL;
	a->tail = tmp;
	if (print == 1)
		write(1, "ra\n", 3);
}
void	ft_rb(t_stack *b, int print)
{
	t_node	*tmp;

	if (b->head == NULL || b->head == b->tail)
		return ;
	tmp = b->head;
	b->head = tmp->next;
	b->head->prev = NULL;
	b->tail->next = tmp;
	tmp->prev = b->tail;
	tmp->next = NULL;
	b->tail = tmp;
	if (print == 1)
		write(1, "rb\n", 3);
}
void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	write(1, "rr\n", 3);
}
