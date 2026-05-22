/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:05:08 by sgarba            #+#    #+#             */
/*   Updated: 2026/05/21 16:59:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_make_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}
void	ft_populate_stack(t_stack *stack, char *argv[])
{
	size_t	i;
	t_node	*new;

	i = 1;
	while (argv[i])
	{
		new = ft_make_node(ft_atoi(argv[i]));
		if (!new)
			return ;
		if (stack->head == NULL && stack->tail == NULL)
		{
			stack->head = new;
			stack->tail = new;
		}
		else
		{
			stack->tail->next = new;
			new->prev = stack->tail;
			stack->tail = new;
		}
		stack->size++;
		i++;
	}
	return ;
}
