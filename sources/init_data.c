#include "../includes/cub3d.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = 0;
	mlx->win = 0;
	mlx->img = 0;
	mlx->addr = 0;
	mlx->bits_per_pixel = 0;
	mlx->line_lenght = 0;
	mlx->endian = 0;
	mlx->set = 0;
}

void	init_map(t_map *map)
{
	map->lines = NULL;
	map->fd = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->floor = 0;
	map->ceil = 0;
}

void	init_data(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	data->map = malloc(sizeof(t_map));
	init_mlx(data->mlx);
	init_map(data->map);
}
