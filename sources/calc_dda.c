#include "../includes/cub3d.h"

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
		if (data->map->y < 0 || data->map->x < 0 || !data->map->map[data->map->y] \
			|| !data->map->map[data->map->y][data->map->x])
			break ;
		if(data->map->map[data->map->y][data->map->x] == '1')
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

int	check_collision(t_map *m, double p_x, double p_y, double d_x, double d_y)
{
	int control;
	double check_px;
	double check_py;

	check_px = p_x + (d_x * 0.059);
	check_py = p_y + (d_y * 0.059);
	control = 0;
	if (check_px < 0 || check_px > WIDTH || check_py < 0 || \
	check_py > HEIGHT || m->map[(int)check_py][(int)check_px] == '1')
		control++;
	return (control);
}

void move_player(t_player *p, t_map *m)
{
	(void)m;
	if (p->move.x == -1 && !check_collision(m, p->pos.x, p->pos.y, p->dir.x, -p->dir.y))
	{
			p->pos.x = p->pos.x - p->dir.y * 0.00001;
			p->pos.y = p->pos.y + p->dir.x * 0.00001;
	}
	if (p->move.x == 1 && !check_collision(m, p->pos.x, p->pos.y, -p->dir.x, p->dir.y))
	{
			p->pos.x = p->pos.x + p->dir.y * 0.00001;
			p->pos.y = p->pos.y - p->dir.x * 0.00001;
	}
	if (p->move.y == 1 && !check_collision(m, p->pos.x, p->pos.y, p->dir.x, p->dir.y))
	{
			p->pos.x = p->pos.x + p->dir.x * 0.00001;
			p->pos.y = p->pos.y + p->dir.y * 0.00001; 
	}
	if (p->move.y == -1 && !check_collision(m, p->pos.x, p->pos.y, -p->dir.x, -p->dir.y))
	{
			p->pos.x = p->pos.x - p->dir.x * 0.00001;
			p->pos.y = p->pos.y - p->dir.y * 0.00001;
	}
	m->x = (int)p->pos.x;
	m->y = (int)p->pos.y;
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

int draw(t_data *data)
{
	int i;

	i = 0;
	while (i < WIDTH)
	{
		move_player(&data->player, data->map);
		rotate_player(data);
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
