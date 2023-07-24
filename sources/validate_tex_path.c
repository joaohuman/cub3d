/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tex_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:49:37 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/23 23:49:38 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_tex_path(t_map *map)
{
	int	i;
	int	status;

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
