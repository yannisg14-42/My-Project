# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_dispatch
{
    char    specifier;
    int     (*handler)(va_list *args);
}   t_dispatch;

int ft_printf(const char*, ...);

int ft_handler_specifier(char specifier, va_list *args);

int ft_print_char(va_list *args);

int ft_print_str(va_list *args);

int ft_print_int(va_list *args);

int ft_print_uint(va_list *args);

int ft_print_hex(va_list *args);

int ft_print_HEX(va_list *args);

int ft_print_ptr(va_list *args);

int ft_print_percent(va_list *args);

#endif