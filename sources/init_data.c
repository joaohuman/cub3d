#include "../includes/cub3d.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Cub3D");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_lenght, &mlx->endian);
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->map = malloc(sizeof(t_map));
	ft_bzero(data->map, sizeof(t_map));
}
