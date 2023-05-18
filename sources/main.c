#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	int fd;
	int i = 0;

	if (check_errors(argc, argv))
		return (-1);
	fd = open(argv[1], O_RDONLY);
	while (i++ < 6)
		printf("%s", get_next_line(fd));
	return (0);
}

char *get_next_line(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}
