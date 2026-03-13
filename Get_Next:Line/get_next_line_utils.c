/* Get the length of a string */
#include "get_next_line.h"
#include <stdlib.h>

size_t    ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
/* Find the \n character or return NULL*/
void    *ft_memchr(const void *ptr, int c, size_t n)
{
    size_t  i;
    unsigned char    *str;

    i = 0;
    str = (unsigned char*)ptr;
    while (i < n)
    {
        if (str[i] == (unsigned char)c)
            return (&str[i]);
        i++;
    }
    return (NULL);
}
/* Extract the line with \n in it*/
char    *ft_extract_new_line(char *static_buff, size_t newline_position)
{
    char    *line;
    size_t  i;

    line = malloc(newline_position + 2);
    i = 0;
    if (!line)
        return (NULL);
    while (i <= newline_position)
    {
        line[i] = static_buff[i];
        i++;
    }
    line[newline_position + 1] = '\0';
    return (line);
}
/* Shift the static buffer to only contain what commes after \n*/
char    *ft_shift_buff(char *static_buff, size_t newline_position)
{
    char    *after_newline;
    size_t  i;
    size_t  j;
    size_t  after_newline_position;

    after_newline_position = ft_strlen(static_buff) - (newline_position + 1);
    after_newline = malloc(after_newline_position + 1);
    i = newline_position + 1;
    j = 0;
    if (!after_newline)
        return (NULL);
    while (static_buff[i])
    {
        after_newline[j] = static_buff[i];
        i++;
        j++;
    }
    after_newline[j] = '\0';
    free (static_buff);
    return (after_newline);

}
/* Apend tmp buff to static buff*/
char    *ft_append_buff(char *static_buff, char *tmp_buff, size_t tmp_size)
{
    char    *full_buff;
    size_t  static_bufflen;
    size_t  i;

    static_bufflen = 0;
    if (static_buff)
        static_bufflen = ft_strlen(static_buff);
    full_buff = malloc(static_bufflen + tmp_size + 1);
    if (!full_buff)
    {
        free(static_buff);
        return (NULL);
    }
    i = 0;
    while (i < (static_bufflen + tmp_size))
    {
        if (i < static_bufflen)
            full_buff[i] = static_buff[i];
        if (i < tmp_size)
            full_buff[static_bufflen + i] = tmp_buff[i - static_bufflen];
        i++;
    }
    full_buff[static_bufflen + tmp_size] = '\0';
    free(static_buff);
    return (full_buff);
}


