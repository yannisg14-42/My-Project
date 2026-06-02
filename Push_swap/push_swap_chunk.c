/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:24:45 by sgarba            #+#    #+#             */
/*   Updated: 2026/06/03 00:10:21 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_arr(int	*arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size -1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*ft_sorted_arr(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*current;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	current = a->head;
	i = 0;
	while (current != NULL)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	ft_sort_int_arr(arr, a->size);
	return (arr);
}

int	ft_get_rank(int *sorted, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_chunk_pos(t_stack *a, t_chunk chunk)
{
	t_node	*current;
	int		pos;
	int		best_pos;

	current = a->head;
	pos = 0;
	best_pos = a->size;
	while (current != NULL)
	{
		if (ft_get_rank(chunk.sorted, chunk.n, current->value) >= 
			chunk.min && ft_get_rank(chunk.sorted, 
				chunk.n, current->value) < chunk.max)
		{
			if (pos < best_pos)
				best_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (best_pos);
}

void	ft_push_chunk(t_stack *a, t_stack *b, t_chunk chunk)
{
	int	rank;
	int	pos;
	int	count;

	count = chunk.max - chunk.min;
	while (count > 0)
	{
		rank = ft_get_rank(chunk.sorted, chunk.n, a->head->value);
		if (rank >= chunk.min && rank < chunk.max)
		{
			ft_pb(a, b);
			count--;
		}
		else
		{
			pos = ft_chunk_pos(a, chunk);
			if (pos <= a->size / 2)
				ft_ra(a, 1);
			else
				ft_rra(a, 1);
		}
	}
}
