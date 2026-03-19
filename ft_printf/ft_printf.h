/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:49:28 by sgarba            #+#    #+#             */
/*   Updated: 2026/03/18 14:49:28 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_dispatch
{
	char	specifier;
	int		(*handler)(va_list *args);
}	t_dispatch;

int	ft_printf(const char *to_print, ...);

int	ft_handler_specifier(char specifier, va_list *args);

int	ft_print_char(va_list *args);

int	ft_print_str(va_list *args);

int	ft_print_int(va_list *args);

int	ft_print_uint(va_list *args);

int	ft_print_hex(va_list *args);

int	ft_print_bighex(va_list *args);

int	ft_print_ptr(va_list *args);

int	ft_print_percent(va_list *args);

int	ft_print_digits(long nb);

int	ft_print_hex_digits(unsigned long nb, char *base);

#endif