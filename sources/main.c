#include "../includes/cub3d.h"

int		create_map(t_map *map)
{
	char *line;
	char *aux;

	line = get_next_line(map->fd);
	if (line == NULL)
		return(error_msg("(Malloc) Error to allocate memory"));
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

int	assign_tex_path(char **tex, char *path)
{
	if (*tex != NULL)
		return (error_msg("There is a path to more than one position"));
	*tex = path;
	if (check_extension(path, ".xpm"))
		return (error_msg("Wrong extension type in texture"));
	return (0);
}

int	is_valid_path(t_map *map)
{
	// int fd;
	// int i;

	// i = 0;
	// while (i < 4)
	// {
	// 	if (i == 0)
	// 		fd = open(map->no, O_RDWR);
	// 	else if (i == 1)
	// 		fd = open(map->so, O_RDWR);
	// 	else if (i == 2)
	// 		fd = open(map->we, O_RDWR);
	// 	else
	// 		fd = open(map->ea, O_RDWR);
	// 	if (fd < 0)
	// 	{
	// 		close (fd);
	// 		return (error_msg("Invalid texture file"));
	// 	}
	// 	close (fd);
	// 	i++;
	// }

	if (check_file(map->no))
		return (-1);
	if (check_file(map->so))
		return (-1);
	if (check_file(map->we))
		return (-1);
	if (check_file(map->ea))
		return (-1);
	return (0);
}

int	validate_tex_path(t_map *map)
{
	int i;
	int status;

	i = 0;
	status = 0;
	while (i <= 5 && !status)
	{
		if (ft_strncmp(map->lines[i], "NO ", 3) == 0)
			status = assign_tex_path(&map->no, map->lines[i] + 3);
		else if (ft_strncmp(map->lines[i], "SO ", 3) == 0)
			status = assign_tex_path(&map->so, map->lines[i] + 3);
		else if (ft_strncmp(map->lines[i], "WE ", 3) == 0)
			status = assign_tex_path(&map->we, map->lines[i] + 3);
		else if (ft_strncmp(map->lines[i], "EA ", 3) == 0)
			status = assign_tex_path(&map->ea, map->lines[i] + 3);
		i++;
	}
	if (status)
		return (-1);
	if (is_valid_path(map))
		return (error_msg("Invalid texture file"));
	return (0);
}

int	validate_map(t_map *map)
{
	if (validate_tex_path(map))
		return (-1);
	//precisamos verificar se esta faltando alguma textura para alguma posicao
	//precisamos checar as cores
	//precisamos verificar se esta faltando alguma cor ser definida
	//precisamos checar os caracteres
	//precisamos chegar se o mapa esta fechado
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
	{
		free_all(&data);
		return (-1);
	}
	free_all(&data);
	// teste.mlx = mlx_init();
	// teste.win = mlx_new_window(teste.mlx, 600, 600, "Hello world!");
	// mlx_key_hook(teste.win, key_hook, &teste);
	// mlx_loop(teste.mlx);
	return (0);
}