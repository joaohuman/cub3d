#include "../includes/cub3d.h"

int	just_one_player(char *players_allowed, char c, int flag)
{
	static int	how_many_players;

	if (players_allowed == NULL && c == '\0' && flag == 1)
		return (how_many_players);
	while (*players_allowed)
		if (*players_allowed++ == c)
			how_many_players++;
	if (how_many_players > 1)
		return (ERROR);
	return (SUCCESS);
}

int	validate_single_player(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = START_OF_MAP;
	j = 0;
	k = ft_strlen_matrix(&map->lines[i]);
	while (k)
	{
		while (map->lines[i][j] != '\0')
		{
			if (just_one_player("NSWE", map->lines[i][j], 0))
				return (error_msg("There is more than one player on the map"));
			j++;
		}
		j = 0;
		i++;
		k--;
	}
	if (just_one_player(NULL, '\0', 1) != 1)
		return (error_msg("There are no players"));
	return (SUCCESS);
}

int	check_around_char(int i, int j, t_map *map)
{
	char	**lines;

	lines = map->lines;
	if (ft_strchr("0NSWE", lines[i][j]) && (
		lines[i][j + 1] == '\0' || lines[i + 1][j + 1] == '\0' || \
		lines[i][j - 1] == '\0' || lines[i + 1][j - 1] == '\0' || \
		lines[i + 1][j] == '\0' || lines[i - 1][j + 1] == '\0' || \
		lines[i - 1][j] == '\0' || lines[i - 1][j - 1] == '\0' || \
		lines[i][j + 1] == ' ' || lines[i + 1][j + 1] == ' ' || \
		lines[i][j - 1] == ' ' || lines[i + 1][j - 1] == ' ' || \
		lines[i + 1][j] == ' ' || lines[i - 1][j + 1] == ' ' || \
		lines[i - 1][j] == ' ' || lines[i - 1][j - 1] == ' ' )
		)
		return (ERROR);
	return (SUCCESS);
}

int	validate_map_borders(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = START_OF_MAP;
	j = 0;
	k = ft_strlen_matrix(&map->lines[i]);
	while (k)
	{
		while (map->lines[i][j] != '\0')
		{
			if (check_around_char(i, j, map))
				return (error_msg("The map is not surrounded by walls"));
			j++;
		}
		j = 0;
		i++;
		k--;
	}
	return (SUCCESS);
}
