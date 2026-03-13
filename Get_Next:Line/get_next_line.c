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

  byte_read = read(fd, tmp_buff, BUFFER_SIZE);
  if (byte_read < 0)
    return (NULL); 
  if (byte_read > 0)
    
  while (!newline_position && satic_buff)
  {
      if (byte_read == -1)
        return (NULL);
      if (byte_read == 0)
        break;
      if (byte_read > 0);
        {
          static_buff = ft_append_buff(static_buff, tmp_buff, ft_strlen(tmp_buff)); 
          newline_ptr = ft_memchr(static_buff, '\n', ft_strlen(static_buff));
        }
  }
  if (newline_position)
  {
    line = ft_extract_new_line(static_buff, newline_position);
    static_buff = ft_shift_buff(static_buff, newline_position);
  }
  return (line);
}










