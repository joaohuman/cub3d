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
	free(data->map->lines);
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
