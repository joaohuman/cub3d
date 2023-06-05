#include "../includes/cub3d.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Cub3D");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_lenght, &mlx->endian);
}

void	init_map(t_map *map)
{
	ft_bzero(map, sizeof(t_map));
}

void init_player(t_player *player)
{
	player->pos.x = 5;
	player->pos.y = 5;
	player->dir.x = 0;
	player->dir.y = -1;
	player->plane.x = 0.66;
	player->plane.y = 0;
}

void init_ray(t_ray *ray)
{
	ray->multiplier = 0;
	ray->cam_pix.x = 0;
	ray->cam_pix.y = 0;
	ray->dir.x = 0;
	ray->dir.y = 0;
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->map = malloc(sizeof(t_map));

	init_map(data->map);
	init_player(&data->player);
	init_ray(&data->ray);
}
