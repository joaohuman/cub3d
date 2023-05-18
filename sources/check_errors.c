#include "../includes/cub3d.h"

int check_errors(int argc, char *argv[]){
    if (argc != 2)
        return (printf("Error\nWrong number of arguments\n"), 0);
    check_extension(argv[1], ".cub");
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
            return (perror("Error\nWrong extension\n"), 0);
        aux++;
        extension++;
    }
    return (1);
}