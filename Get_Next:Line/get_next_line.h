#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <stddef.h>
# include <unistd.h>

size_t   ft_strlen(const char *s);

void     *ft_memchr(const void *ptr, int c, size_t n);

char     *ft_extract_new_line(char *buff, size_t newline_position);

char     *ft_shift_buff(char *buff, size_t newline_position);

char     *ft_append_buff(char *buff, char *tmp_buff, size_t tmp_size);

ssize_t  ft_read_buff(int fd, char **static_buff);

char     *get_next_line(int fd);

#endif
