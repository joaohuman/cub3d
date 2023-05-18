#include "../includes/cub3d.h"

int main(int argc, char *argv[])
{
    int fd;
    int i = 0;

    check_errors(argc, argv);
    fd = open(argv[1], O_RDONLY);
    while (i++ < 5)
        printf("%s", get_next_line(fd));
    return (0);
}

char *get_next_line(int fd) 
{
  char *s = malloc(10000), *c = s;
  while (read(fd, c, 1) > 0 && *c++ != '\n');
  return c > s ? (*c = 0, s) : (free(s), NULL);
}