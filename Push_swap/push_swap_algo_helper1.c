#include "push_swap.h"

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
	while (pos_a > a->size / 2 && pos_b > b->size / 2)
	{
		ft_rrr(a, b);
		pos_a--;
		pos_b--;
	}
	return ;
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
	while (pos_a > a->size / 2)
	{
		ft_rra(a, 1);
		pos_a--;
	}
	return ;
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
	while (pos_b > b->size / 2)
	{
		ft_rrb(b, 1);
		pos_b--;
	}
	return ;
}
void	ft_execute(t_stack *a, t_stack *b, t_node *best)
{
	ft_execute_combined(a, b, best);
	ft_execute_a(a, best);
	ft_execute_b(b, best);
	ft_pb(a, b);
	return ;
}