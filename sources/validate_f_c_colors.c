/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_f_c_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:49:33 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/23 23:49:34 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_floor_ceil_colors(t_map *map)
{
	int	i;
	int	status;

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

int	assign_color(char c, char *line, t_map *map)
{
	char	**rgb_split;
	int		rgb[3];
	int		i;

	if (how_many_commas(line) != 2 || num_between_commas(line))
		return (error_msg("Error in rgb colors, \
							inform as follows: 255,255,255"));
	rgb_split = ft_split(line, ',');
	i = 0;
	while (i < 3)
	{
		if (validate_and_assign(rgb_split, rgb, i))
			return (-1);
		i++;
	}
	free_matrix(rgb_split);
	if (define_color(c, map, rgb))
		return (-1);
	return (0);
}

int	validate_and_assign(char **rgb_split, int *rgb, int i)
{
	char	*trim_line;

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
	return (0);
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
