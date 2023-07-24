/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:48:49 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/23 23:48:50 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_check_map(t_data *data)
{
	free_matrix(data->map->lines);
	free_matrix(data->map->map);
	free(data->map);
	return (-1);
}

void	free_all(t_data *data)
{
	free_matrix(data->map->lines);
	free_matrix(data->map->map);
	free(data->map);
}

void	free_matrix(char **matrix)
{
	int	i;

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
