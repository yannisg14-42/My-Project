/* Get the length of a string */
#include "get_next_line.h"

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
char    *ft_extract_new_line(char *buff, size_t newline_position)
{
    char    *new_line;
    size_t  i;

    new_line = malloc(newline_position + 2);
    i = 0;
    if (!new_line)
        return (NULL);
    while (i <= newline_position)
    {
        new_line[i] = buff[i];
        i++;
    }
    new_line[newline_position + 1] = '\0';
    return (new_line);
}
/* Shift the static buffer to only contain what commes after \n*/
char    *ft_shift_buff(char *buff, size_t newline_position)
{
    char    *after_new_line;
    size_t  i;
    size_t  j;
    size_t  after_newline_position;

    after_newline_position = ft_strlen(buff) - (newline_position + 1);
    after_new_line = malloc(after_newline_position + 1);
    i = newline_position + 1;
    j = 0;
    if (!after_new_line)
        return (NULL);
    while (buff[i])
    {
        after_new_line[j] = buff[i];
        i++;
        j++;
    }
    after_new_line[j] = '\0';
    free (buff);
    return (after_new_line);

}
/* Apend tmp buff to static buff*/
char    *ft_append_buff(char *buff, char *tmp_buff, size_t tmp_size)
{
    char    *fullbuff;
    size_t  bufflen;
    size_t  i;

    bufflen = 0;
    if (buff)
        bufflen = ft_strlen(buff);
    fullbuff = malloc(bufflen + tmp_size + 1);
    if (!fullbuff)
        return (NULL);
    i = 0;
    while (i < bufflen)
    {
        fullbuff[i] = buff[i];
        i++;
    }
    i = 0;
    while (i < tmp_size)
    {
        fullbuff[bufflen + i] = tmp_buff[i];
        i++;
    }
    fullbuff[bufflen + tmp_size] = '\0';
    return (fullbuff);
}


