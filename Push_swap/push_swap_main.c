/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:10:27 by sgarba            #+#    #+#             */
/*   Updated: 2026/06/19 23:27:43 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate_arg(char *argv[])
{
	int		dup;
	int		number;
	size_t	i;

	i = 0;
	while (argv[i])
	{
		number = ft_is_valid_int(argv[i]);
		if (number == 0)
			return (1);
		i++;
	}
	dup = ft_is_dup(argv);
	if (dup == 1)
		return (1);
	return (0);
}

void	ft_init_stack(t_stack *a, t_stack *b)
{
	a->head = NULL;
	a->tail = NULL;
	a->size = 0;
	b->head = NULL;
	b->tail = NULL;
	b->size = 0;
}

void	ft_free_all(t_stack *stak)
{
	t_node	*tmp;

	while (stak->head != NULL)
	{
		tmp = stak->head;
		stak->head = stak->head->next;
		free(tmp);
	}
}

void	ft_run(int argc, char *argv[], t_stack *a, t_stack *b)
{
	if (ft_is_sorted(a))
		return ;
	if (argc == 3 && ft_atoi(argv[1]) > ft_atoi(argv[2]))
		ft_sa(a, 1);
	else if (argc == 4)
		ft_sort_three(a);
	else if (argc > 4)
		ft_algorithm(a, b);
}

int	main(int argc, char *argv[])
{
	int		valide;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	valide = ft_validate_arg(argv + 1);
	if (valide == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_init_stack(&a, &b);
	ft_populate_stack(&a, argv);
	if (argc == 2)
	{
		ft_free_all(&a);
		return (0);
	}
	ft_run(argc, argv, &a, &b);
	ft_free_all(&a);
	ft_free_all(&b);
	return (0);
}
