#include "push_swap.h"

t_node	*ft_find_min(t_stack *stak)
{
	t_node	*min;
	t_node	*current;

	min = stak->head;
	current = stak->head->next;
	while (current != NULL)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}
int	ft_get_position(t_node *nod, t_stack *stak)
{
	int		count;
	t_node	*current;

	count = 0;
	current = stak->head;
	while (current != nod)
	{
		current = current->next;
		count++;
	}
	return (count);
}
t_node	*ft_find_target(t_stack *stack, int x)
{
	t_node	*current;
	t_node	*target;

	current = stack->head;
	target = NULL;
	while (current != NULL)
	{
		if (current->value > x)
		{
			if (target == NULL || current->value < target->value)
				target = current;
		}
		current = current->next;
	}
	if (target == NULL)
		target = ft_find_min(stack);
	return (target);
}
int	ft_get_cost(int cost_a, int cost_b, int size_a, int size_b)
{
	int	real_a;
	int	real_b;

	real_a = cost_a;
	real_b = cost_b;
	if (cost_a > (size_a / 2))
		real_a = size_a - cost_a;
	if (cost_b > (size_b / 2))
		real_b = size_b - cost_b;
	if ((cost_a <= size_a / 2) == (cost_b <= size_b / 2))
	{
	if (real_a > real_b)
		return (real_a);
	return (real_b);
	}
	return (real_a + real_b);
}
