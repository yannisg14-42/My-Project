/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:48:23 by sgarba            #+#    #+#             */
/*   Updated: 2026/05/25 20:48:23 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, int print)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (a->head == NULL || a->head == a->tail)
		return ;
	tmp = a->head;
	tmp1 = tmp->next;
	tmp->next = tmp1->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	a->head = tmp1;
	tmp1->next = tmp;
	tmp1->prev = NULL;
	tmp->prev = tmp1;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, int print)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (b->head == NULL || b->head == b->tail)
		return ;
	tmp = b->head;
	tmp1 = tmp->next;
	tmp->next = tmp1->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	b->head = tmp1;
	tmp1->next = tmp;
	tmp1->prev = NULL;
	tmp->prev = tmp1;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	write(1, "ss\n", 3);
}
