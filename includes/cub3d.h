#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int check_errors(int argc, char *argv[]);
int check_extension(char *arg, char *extension);
int check_file(char *file_name);

#endif