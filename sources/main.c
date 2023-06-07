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
	if (map->no && check_file(map->no))
		return (-1);
	if (map->so && check_file(map->so))
		return (-1);
	if (map->we && check_file(map->we))
		return (-1);
	if (map->ea && check_file(map->ea))
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

int	all_tex_path_hav_been_set(t_map *map)
{
	if (map->no == NULL)
		return (error_msg("the path of a texture is missing (no)"));
	else if (map->so == NULL)
		return (error_msg("the path of a texture is missing (so)"));
	else if (map->we == NULL)
		return (error_msg("the path of a texture is missing (we)"));
	else if (map->ea == NULL)
		return (error_msg("the path of a texture is missing (ea)"));
	return (0);
}

int	ft_str_is_digit(char *str)
{
	while (*str)
		if (ft_isdigit(*str++) == 0)
			return (0);
	return (1);
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

int	define_color(char c, t_map *map, int *rgb)
{
	if (c == 'F')
	{
		if (map->floor)
			return (error_msg("There are duplicate colors to floor"));
		map->floor = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	}
	else
	{
		if (map->ceil)
			return (error_msg("There are duplicate colors to ceil"));
		map->ceil = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	}
	return (0);
}

int	ft_strlen_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int num_between_commas(char *line)
{
	int		len;
	int		i;
	char	**split_test;

	i = 0;
	len = 0;
	split_test = ft_split(line, ',');
	if (ft_strlen_matrix(split_test) != 3)
	{
		free_matrix(split_test);
		return (-1);
	}
	while (split_test[i])
	{
		len = ft_strlen(split_test[i]);
		if (len < 1 || len > 3)
		{
			free_matrix(split_test);
			return (-1);
		}
		i++;
	}
	free_matrix(split_test);
	return (0);
}

int how_many_commas(char *line)
{
	int i;
	int comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (i == comma)
		return (-1);
	return(comma);
}

int	assign_color(char c, char *line, t_map *map)
{
	char **rgb_split;
	char *trim_line;
	int rgb[3];
	int i;

	if (how_many_commas(line) != 2 || num_between_commas(line))
		return(error_msg("Error in rgb colors, inform as follows: 255,255,255"));
	rgb_split = ft_split(line, ',');
	i = 0;
	while (i < 3)
	{
		if (!ft_str_is_digit(rgb_split[i]))
		{
			free_matrix(rgb_split);
			return (error_msg("Invalid RGB color"));
		}
		trim_line = ft_strtrim(rgb_split[i], " \n\t\r");
		rgb[i] = ft_atoi(trim_line);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free_matrix(rgb_split);
			free(trim_line);
			return (error_msg("Invalid RGB color"));
		}
		free(trim_line);
		i++;
	}
	free_matrix(rgb_split);
	if (define_color(c, map, rgb))
		return (-1);
	return (0);
}

int	validate_floor_ceil_colors(t_map *map)
{
	int i;
	int status;

	i = 0;
	status = 0;
	while (i <= 5 && !status)
	{
		if (ft_strncmp(map->lines[i], "F ", 2) == 0)
			status = assign_color('F', map->lines[i] + 2, map);
		else if (ft_strncmp(map->lines[i], "C ", 2) == 0)
			status = assign_color('C', map->lines[i] + 2, map);
		i++;
	}
	if (status)
		return (-1);
	if (!map->floor || !map->ceil)
		return (error_msg("One of the colors was missing"));
	if (map->floor == map->ceil)
		return (error_msg("Ceiling and floor colors cannot be the same"));
	return (0);
}

int	validate_map(t_map *map)
{
	if (validate_tex_path(map))
		return (-1);
	if (all_tex_path_hav_been_set(map))
		return (-1);
	if (validate_floor_ceil_colors(map))
		return (-1);
	
	//precisamos checar os caracteres permitidos
	//precisamos checar se o mapa esta fechado
	return (0);
}

int	check_map(t_map *map)
{
	if (create_map(map))
		return (-1);
	if (validate_map(map))
		return (-1);
	printf("ceil color: %i\n", map->ceil);
	printf("floor color: %i\n", map->floor);
	return (0);
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