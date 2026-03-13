#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char  *get_next_line(int fd)
{
  static   char  *static_buff;
  char     tmp_buff[BUFFER_SIZE];
  ssize_t  byte_read;
  void     *newline_ptr;
  char     *line;

  if (static_buff)
    newline_ptr = ft_memchr(static_buff, '\n', ft_strlen(static_buff));
  while (!newline_ptr)
  {
    byte_read = read(fd, tmp_buff, BUFFER_SIZE);
    if (byte_read == -1)
      return (NULL);
    if (byte_read == 0)
      break;
    if (byte_read > 0)
      {
        static_buff = ft_append_buff(static_buff, tmp_buff, byte_read); 
        newline_ptr = ft_memchr(static_buff, '\n', ft_strlen(static_buff));
      }
  }
  if (newline_ptr)
  {
    line = ft_extract_new_line(static_buff, (size_t)((char *)newline_ptr - static_buff));
    static_buff = ft_shift_buff(static_buff, (size_t)((char *)newline_ptr - static_buff));
  }
  return (line);
}



















