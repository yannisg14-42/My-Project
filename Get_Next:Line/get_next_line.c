#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char  *get_next_line(int fd)
{
  static   char  *static_buff;
  char     tmp_buff[BUFFER SIZE];
  ssize_t  byte_read;
  size_t   newline_position;
  char     *line;

  
}




