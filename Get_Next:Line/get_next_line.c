#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char  *get_next_line(int fd)
{
  static   char  *static_buff;
  char     tmp_buff[BUFFER_SIZE];
  ssize_t  byte_read;
  size_t   newline_position;
  char     *line;

  newline_position = ft_memchr(static_buff, '\n', BUFFER_SIZE);
  while (!newline_position && static_buff)
  {
    read(fd, tmp_buff, BUFFER_SIZE);
      if (byte_read == -1)

      else if (byte_read == 0)
        break;
      else if (byte_read > 0)
        static_buff = ft_append_buff(static_buff, tmp_buff, byte_read);
  }
  if (newline_position)
  {
    ft_extract_new_line(static_buff, newline_position);
    ft_shift_buff(static_buff, newline_position);
  }
  return (line);
}







