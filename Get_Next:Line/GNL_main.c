#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

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
