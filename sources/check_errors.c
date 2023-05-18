#include "../includes/cub3d.h"

int check_errors(int argc, char *argv[]){
    if (argc != 2)
        return (perror("Error\nWrong number of arguments\n"), -1);
    if (check_extension(argv[1], ".cub"))
        return -1;
    if (check_file(argv[1]))
        return -1;
    return 0;
}

int check_extension(char *arg, char *extension)
{
    char *aux;

    aux = arg;
    while (*aux != '.')
        aux++;
    while (*aux && *extension)
    {
        if (*aux != *extension)
            return (perror("Error\nWrong extension\n"), -1);
        aux++;
        extension++;
    }
    return (0);
}

int check_file(char *file_name)
{
    int fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return (perror("Error\n"), -1);
    return (0);
}