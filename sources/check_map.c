#include "../includes/cub3d.h"

int	check_map(t_map *map)
{
	if (create_map(map))
		return (ERROR);
	if (validate_map(map))
		return (ERROR);
	return (SUCCESS);
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
	return (SUCCESS);
}

int	validate_chars(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = START_OF_MAP;
	j = 0;
	k = ft_strlen_matrix(&map->lines[i]);
	while (k != 0)
	{
		while (map->lines[i][j] != '\0')
		{
			if (!ft_strchr(" 01NSWE", map->lines[i][j]))
				return (error_msg("There are \
disallowed characters on the map"));
			j++;
		}
		j = 0;
		i++;
		k--;
	}
	return (SUCCESS);
}

int	validate_map(t_map *map)
{
	if (validate_tex_path(map))
		return (ERROR);
	if (all_tex_path_hav_been_set(map))
		return (ERROR);
	if (validate_floor_ceil_colors(map))
		return (ERROR);
	if (validate_chars(map))
		return (ERROR);
	if (validate_single_player(map))
		return (ERROR);
	if (validate_map_borders(map))
		return (ERROR);
	return (SUCCESS);
}
