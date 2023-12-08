#include "get_next_line.h"

#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>



int main()
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("romeo&juliet.txt", O_RDONLY);
	printf("%d->%s",lines++, line = get_next_line(fd));
	free(line);
	line = NULL;
	printf("%d->%s",lines++, line = get_next_line(fd));
	free(line);
	line = NULL;
	printf("%d->%s",lines++, line = get_next_line(fd));
	free(line);
	line = NULL;
	printf("%d->%s",lines++, line = get_next_line(fd));
	free(line);
	line = NULL;
	printf("%d->%s",lines++, line = get_next_line(fd));
	free(line);
	line = NULL;
	printf("%d->%s",lines++, line = get_next_line(fd));
	free(line);
	line = NULL;

    close(fd);
    return(0);
}