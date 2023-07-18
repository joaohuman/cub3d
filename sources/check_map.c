#include "../includes/cub3d.h"

int	check_map(t_map *map, t_player *p)
{
	if (create_map(map, p))
		return (ERROR);
	if (validate_map(map))
		return (ERROR);
	return (SUCCESS);
}

int variable_map(t_map *m, char **lines)
{
	int i;

	i = 0;
	m->map = malloc(sizeof(char *) * ft_strlen_matrix(lines + 6) + 1);
	while (i < ft_strlen_matrix(lines + 6))
	{
		m->map[i] = ft_strdup(lines[i + 6]);
		i++;
	}
	return (0);
}

int	create_map(t_map *m, t_player *p)
{
	char	*line;
	char	*aux;

	line = get_next_line(m->fd);
	if (line == NULL)
		return (error_msg("(Malloc) Error to allocate memory"));
	while (1)
	{
		aux = get_next_line(m->fd);
		if (aux == NULL)
			break ;
		line = ft_strjoin_free(line, aux);
		free(aux);
	}
	m->lines = ft_split(line, '\n');
	variable_map(m, m->lines);
	disc_player_pos(m->map, p);
	m->x = (int)p->pos.x;
	m->y = (int)p->pos.y;
	free(line);
	close(m->fd);
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
