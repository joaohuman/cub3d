#include "../includes/cub3d.h"

void dist_to_side(t_data *data)
{
	if (data->ray.dir.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.dist_to_side.x = (data->player.pos.x - data->map->x) * data->ray.delta_dist.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.dist_to_side.x = (data->map->x + 1.0 - data->player.pos.x) * data->ray.delta_dist.x;
	}
	if (data->ray.dir.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.dist_to_side.y = (data->player.pos.y - data->map->y) * data->ray.delta_dist.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.dist_to_side.y = (data->map->y + 1.0 - data->player.pos.y) * data->ray.delta_dist.y;
	}
}

void	perform_dda(t_data *data, t_ray *ray)
{
	while (true)
	{
		if(ray->dist_to_side.x < ray->dist_to_side.y)
		{
			ray->dist_to_side.x += ray->delta_dist.x;
			data->map->x += ray->step.x;
			ray->hit_side = 0;
		}
		else
		{
			ray->dist_to_side.y += ray->delta_dist.y;
			data->map->y += ray->step.y;
			ray->hit_side = 1;
		}
		if (data->map->y < 0 || data->map->x < 0 || !data->map->lines[data->map->y] \
			|| !data->map->lines[data->map->y][data->map->x])
			break ;
		if(data->map->lines[data->map->y][data->map->x] == '1')
			break ;
	}
}

void calc_line_heigh(t_ray *ray, t_player *player)
{
	if (ray->hit_side == 0)
		ray->perp_dist = (ray->dist_to_side.x - ray->delta_dist.x);
	else
		ray->perp_dist = (ray->dist_to_side.y - ray->delta_dist.y);
	ray->line_height = (int)(HEIGHT / ray->perp_dist);
	ray->start_line = -(ray->line_height) / 2 + HEIGHT / 2;
	if (ray->start_line < 0)
		ray->start_line = 0;
	ray->end_line = ray->line_height / 2 + HEIGHT / 2;
	if (ray->end_line >= HEIGHT)
		ray->end_line = HEIGHT - 1;
	if (ray->hit_side == false)
		ray->wall_x = player->pos.y + ray->perp_dist * ray->dir.y;
	else
		ray->wall_x = player->pos.x + ray->perp_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}


double discover_multiplier(int pixel)
{
	double multiplier;

	multiplier = 2 * pixel / (double)WIDTH - 1;
	return (multiplier);
}

void draw_square(t_mlx *mlx, int x, int y, int size, int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(mlx, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void draw_minimapa(t_data *data)
{
	int i;
	int j;
	int x;
	int y;

	i = START_OF_MAP;
	while (i < ft_strlen_matrix(data->map->lines + 6) + 6)
	{
		j = 0;
		while (j < ft_line_len(data->map->lines + 6))
		{
			x = j * 4;
			y = i * 4;
			if (data->map->lines[i][j] == '1')
				draw_square(&data->mlx, x, y, 4, 0x00FF00);
			else if (data->map->lines[i][j] == '0')
				draw_square(&data->mlx, x, y, 4, 0x000000);
			j++;
		}
		i++;
	}
	draw_square(&data->mlx, data->player.pos.x * 4, data->player.pos.y * 4, 4, 0xFF0000);
}

void draw_image(t_data *data, int i)
{
	int y;

	y = 0;
	while(y < data->ray.start_line)
	{
		my_mlx_pixel_put(&data->mlx, i, y, data->map->ceil);
		y++;
	}
	while (y < data->ray.end_line)
	{
		if (data->ray.hit_side == 0)
			my_mlx_pixel_put(&data->mlx, i, y, 8388608);
		else
			my_mlx_pixel_put(&data->mlx, i, y, 16711680);
		y++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(&data->mlx, i, y, data->map->floor);
		y++;
	}
}

void create_dda(t_data *data)
{
	data->ray.cam_pix.x = data->player.plane.x * data->ray.multiplier;
	data->ray.cam_pix.y = data->player.plane.y * data->ray.multiplier;
    data->ray.dir.x = data->player.dir.x + data->ray.cam_pix.x;
	data->ray.dir.y = data->player.dir.y + data->ray.cam_pix.y;
	data->map->x = (int)data->player.pos.x;
	data->map->y = (int)data->player.pos.y;
	data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
	data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);
}

int draw(t_data *data)
{
	int i;

	i = 0;
	while (i < WIDTH)
	{
		if (data->player.move.x == 1)
		{
			data->player.pos.x += data->player.dir.x * 0.1;
			data->player.pos.y += data->player.dir.y * 0.1;
		}
		if (data->player.move.x == -1)
		{
			data->player.pos.x -= data->player.dir.x * 0.1;
			data->player.pos.y -= data->player.dir.y * 0.1;
		}
		if (data->player.move.y == 1)
		{
			data->player.pos.x += data->player.dir.y * 0.1;
			data->player.pos.y -= data->player.dir.x * 0.1;
		}
		if (data->player.move.y == -1)
		{
			data->player.pos.x -= data->player.dir.y * 0.1;
			data->player.pos.y += data->player.dir.x * 0.1;
		}
		data->ray.multiplier = discover_multiplier(i);
		create_dda(data);
		dist_to_side(data);
		perform_dda(data, &data->ray);
		calc_line_heigh(&data->ray, &data->player);
		draw_image(data, i);
		i++;
	}
	draw_minimapa(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
