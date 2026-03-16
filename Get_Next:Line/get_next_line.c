#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

ssize_t ft_read_buff(int fd, char **static_buff)
{
  char    tmp_buff[BUFFER_SIZE];
  ssize_t byte_read;

  byte_read = read(fd, tmp_buff, BUFFER_SIZE);
  if (byte_read == -1)
  {
    free(*static_buff);
    *static_buff = NULL;
    return (-1);
  }
  if (byte_read == 0)
    return (0);
  if (byte_read > 0)
    *static_buff = ft_append_buff(*static_buff, tmp_buff, byte_read);
  return (byte_read);
}

char  *get_next_line(int fd)
{
  static char  *static_buff;
  void         *newline_ptr;
  char         *line;

  newline_ptr = NULL;
  line = NULL;
  if (static_buff)
    newline_ptr = ft_memchr(static_buff, '\n', ft_strlen(static_buff));
  while (!newline_ptr && ft_read_buff(fd, &static_buff) > 0)
    newline_ptr = ft_memchr(static_buff, '\n', ft_strlen(static_buff));
  if (!newline_ptr && static_buff && ft_strlen(static_buff) > 0)
  {
    line = ft_extract_new_line(static_buff, (ft_strlen(static_buff)-1));
    free(static_buff);
    static_buff = NULL;
  }
  if (newline_ptr)
  {
    line = ft_extract_new_line(static_buff, (size_t)((char *)newline_ptr - static_buff));
    static_buff = ft_shift_buff(static_buff, (size_t)((char *)newline_ptr - static_buff));
  }
  return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		line_nb;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: cannot open file '%s'\n", argv[1]);
		return (1);
	}
	line_nb = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[line %d]: %s", line_nb, line);
		free(line);
		line_nb++;
	}
	close(fd);
	return (0);
}
