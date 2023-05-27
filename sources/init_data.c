#include "../includes/cub3d.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 600, 600, "Cub3D");
	mlx->img = mlx_new_image(mlx->mlx, 600, 600);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_lenght, &mlx->endian);
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
	data->map = malloc(sizeof(t_map));
	init_map(data->map);
}