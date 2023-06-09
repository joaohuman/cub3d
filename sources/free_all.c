#include "../includes/cub3d.h"

void	free_all(t_data *data)
{
	free_matrix(data->map->lines);
	free(data->mlx);
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
