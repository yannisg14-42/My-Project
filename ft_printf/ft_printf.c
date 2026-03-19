/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:49:20 by sgarba            #+#    #+#             */
/*   Updated: 2026/03/18 15:55:09 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handler_specifier(char specifier, va_list *args)
{
	int			i;
	t_dispatch	table[10];

	table[0] = (t_dispatch){'c', ft_print_char};
	table[1] = (t_dispatch){'s', ft_print_str};
	table[2] = (t_dispatch){'d', ft_print_int};
	table[3] = (t_dispatch){'i', ft_print_int};
	table[4] = (t_dispatch){'u', ft_print_uint};
	table[5] = (t_dispatch){'x', ft_print_hex};
	table[6] = (t_dispatch){'X', ft_print_bighex};
	table[7] = (t_dispatch){'p', ft_print_ptr};
	table[8] = (t_dispatch){'%', ft_print_percent};
	table[9] = (t_dispatch){0, NULL};
	i = 0;
	while (table[i].handler != NULL)
	{
		if ((table[i]).specifier == specifier)
			return (table[i].handler(args));
		i++;
	}
	return (0);
}

int	ft_printf(const char *to_print, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, to_print);
	while (to_print[i])
	{
		if (to_print[i] == '%' && to_print[i + 1] != '\0')
		{
			i++;
			count += ft_handler_specifier(to_print[i], &args);
		}
		else
		{
			write(1, &to_print[i], 1);
			count += 1;
		}
		i++;
	}
	va_end(args);
	return (count);
}
