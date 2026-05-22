#include "push_swap.h"

void	ft_pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a->head == NULL)
		return ;
	tmp = a->head;
	a->head = a->head->next;
	if (a->head != NULL)
		a->head->prev = NULL;
	else
		a->tail = NULL;
	tmp->next = NULL;
	if (b->head == NULL)
	{
		b->head = tmp;
		b->tail = tmp;
	}
	else
	{
		tmp->next = b->head;
		b->head->prev = tmp;
		b->head = tmp;
	}
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}
void	ft_pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->head == NULL)
		return ;
	tmp = b->head;
	b->head = b->head->next;
	if (b->head != NULL)
		b->head->prev = NULL;
	else
		b->tail = NULL;
	tmp->next = NULL;
	if (a->head == NULL)
	{
		a->head = tmp;
		a->tail = tmp;
	}
	else
	{
		tmp->next = a->head;
		a->head->prev = tmp;
		a->head = tmp;
	}
	b->size--;
	a->size++;
	write(1, "pa\n", 3);
}
