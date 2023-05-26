#include "../includes/cub3d.h"

int		create_map(t_map *map)
{
	char *line;
	char *aux;

	line = get_next_line(map->fd);
	if (line == NULL)
		return(-1);
	while (1)
	{
		aux = get_next_line(map->fd);
		if (aux == NULL)
			break;
		line = ft_strjoin_free(line, aux);
		free(aux);
	}
	map->lines = ft_split(line, '\n');
	free(line);
	close(map->fd);
	return (0);
}

int	validate_tex(t_map *map)
{
	int i;

	i = 0;
	while (i <= 5)
	{
		if (ft_strncmp(map->lines[i], "NO ", 3) == 0)
			map->no = map->lines[i] + 3;
		else if (ft_strncmp(map->lines[i], "SO ", 3) == 0)
			map->so = map->lines[i] + 3;
		else if (ft_strncmp(map->lines[i], "WE ", 3) == 0)
			map->we = map->lines[i] + 3;
		else if (ft_strncmp(map->lines[i], "EA ", 3) == 0)
			map->ea = map->lines[i] + 3;
		i++;
	}
	printf("%s\n", map->no);
	printf("%s\n", map->so);
	printf("%s\n", map->we);
	printf("%s\n", map->ea);
	return (0);
}

int	validate_map(t_map *map)
{
	if (validate_tex(map))
		return (-1);
	return (0);
}

int	check_map(t_map *map)
{
	if (create_map(map))
		return (-1);
	if (validate_map(map))
		return (-1);
	return (0);
}

void	free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
		i++;
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
}

void	free_all(t_data *data)
{
	free_matrix(data->map->lines);
	free(data->mlx);
	free(data->map);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_errors(argc, argv))
		return (-1);
	init_data(&data);
	data.map->fd = open(argv[1], O_RDWR);
	if (check_map(data.map))
		return (-1);
	free_all(&data);
	// teste.mlx = mlx_init();
	// teste.win = mlx_new_window(teste.mlx, 600, 600, "Hello world!");
	// mlx_key_hook(teste.win, key_hook, &teste);
	// mlx_loop(teste.mlx);
	return (0);
}
