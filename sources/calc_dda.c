#include "../includes/cub3d.h"

void create_dda(t_data *data)
{
	data->ray.cam_pix.x = data->player.plane.x * data->ray.multiplier;
	data->ray.cam_pix.y = data->player.plane.y * data->ray.multiplier;
    data->ray.dir.x = data->player.dir.x + data->ray.cam_pix.x;
	data->ray.dir.y = data->player.dir.y + data->ray.cam_pix.y;
	data->ray.map.x = (int)data->player.pos.x;
	data->ray.map.y = (int)data->player.pos.y;
	data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
	data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);
}

void dist_to_side(t_data *data)
{
	if (data->ray.dir.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.dist_to_side.x = (data->player.pos.x - data->ray.map.x) * data->ray.delta_dist.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.dist_to_side.x = (data->ray.map.x + 1.0 - data->player.pos.x) * data->ray.delta_dist.x;
	}
	if (data->ray.dir.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.dist_to_side.y = (data->player.pos.y - data->ray.map.y) * data->ray.delta_dist.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.dist_to_side.y = (data->ray.map.y + 1.0 - data->player.pos.y) * data->ray.delta_dist.y;
	}
}

void	perform_dda(t_data *data, t_ray *ray)
{
	while (true)
	{
		if(ray->dist_to_side.x < ray->dist_to_side.y)
		{
			ray->dist_to_side.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->hit_side = 0;
		}
		else
		{
			ray->dist_to_side.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->hit_side = 1;
		}
		if (ray->map.y < 0 || ray->map.x < 0 || !data->map->map[ray->map.y] \
			|| !data->map->map[ray->map.y][ray->map.x])
			break ;
		if(data->map->map[ray->map.y][ray->map.x] == '1')
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

int	check_collision(t_data *d, double x, double y)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT || d->map->map[(int)y][(int)x] == '1')
		return (true);
	return (false);
}

void rotate_player(t_data *d)
{
	if (d->player.rotate == 1)
	{
		rotate(&d->player.dir.x, &d->player.dir.y, ROT_SPEED);
		rotate(&d->player.plane.x, &d->player.plane.y, ROT_SPEED);
	}
	if (d->player.rotate == 2)
	{
		rotate(&d->player.dir.x, &d->player.dir.y, -ROT_SPEED);
        rotate(&d->player.plane.x, &d->player.plane.y, -ROT_SPEED);
	}
}

void pixel_added(t_data *d)
{
	d->text.size = SPRITE_SIZE;
	d->text.x = (int)(d->ray.wall_x * d->text.size);
	if ((d->ray.hit_side == false && d->ray.dir.x < 0) || (d->ray.hit_side == true
			&& d->ray.dir.y > 0))
		d->text.x = d->text.size - d->text.x - 1;
	d->text.step = 1.0 * d->text.size / d->ray.line_height;
	d->text.pos = (d->ray.start_line - HEIGHT / 2 + d->ray.line_height / 2) * d->text.step;
}

int draw(t_data *data)
{
	int i;

	i = 0;
	while (i < WIDTH)
	{
		rotate_player(data);
		data->ray.multiplier = discover_multiplier(i);
		create_dda(data);
		dist_to_side(data);
		perform_dda(data, &data->ray);
		calc_line_heigh(&data->ray, &data->player);
		pixel_added(data);
		draw_image(data, i);
		i++;
	}
	draw_minimapa(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
