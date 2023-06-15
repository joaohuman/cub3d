#include "../includes/cub3d.h"

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

int	create_map(t_map *map)
{
	char	*line;
	char	*aux;

	line = get_next_line(map->fd);
	if (line == NULL)
		return (error_msg("(Malloc) Error to allocate memory"));
	while (1)
	{
		aux = get_next_line(map->fd);
		if (aux == NULL)
			break ;
		line = ft_strjoin_free(line, aux);
		free(aux);
	}
	map->lines = ft_split(line, '\n');
	free(line);
	close(map->fd);
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
	return (0);
}
