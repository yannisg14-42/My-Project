#include "push_swap.h"

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
			cost = ft_get_cost(ft_get_position(current, a), ft_get_position(ft_find_target(b, current->value), b), a->size, b->size);
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
	while (a->head != ft_find_min(a))
		ft_ra(a, 1);
}
