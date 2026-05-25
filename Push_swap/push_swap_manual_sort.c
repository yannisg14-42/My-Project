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
	else if(x < y && y > z && x < z)
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
	t_node	*target;

	target = NULL;
	while (b->head != NULL)
	{
		target = ft_find_target(a, b->head->value);
		while (a->head != target)
			ft_ra(a, 1);
		ft_pa(a, b);
	}
}
