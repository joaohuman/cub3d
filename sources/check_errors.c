#include "../includes/cub3d.h"

int	error_msg(char *msg)
{
	printf("Error\n%s\n", msg);
	return (-1);
}

int	check_errors(int argc, char *argv[])
{
	if (argc != 2)
		return (error_msg("Need just 2 args 'cub3d' and 'map_you_chose'"));
	if (check_extension(argv[1], ".cub"))
		return (error_msg("Wrong extension type"));
	if (check_file(argv[1]))
		return (error_msg("Invalid file"));
	return (0);
}

int	check_extension(char *arg, char *extension)
{
	int i;

	i = 0;
	while (arg[i])
		i++;
	--i;
	while (arg[i] && arg[i] != '.')
		i--;
	while (arg[i] || *extension)
	{
		if (arg[i] != *extension)
			return (-1);
		i++;
		extension++;
	}
	return (0);
}

int	check_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (0);
}
