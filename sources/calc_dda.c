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
			ray->hit_side = false;
		}
		else
		{
			ray->dist_to_side.y += ray->delta_dist.y;
			data->map->y += ray->step.y;
			ray->hit_side = true;
		}
		if (data->map->y < 0 || data->map->x < 0 || !data->map->lines[data->map->y] \
			|| !data->map->lines[data->map->y][data->map->x])
			break ;
		if(data->map->lines[data->map->y][data->map->x] == '1')
			break ;
	}
}

double discover_multiplier(int pixel)
{
	double multiplier;

	multiplier = 2 * (pixel / WIDTH) - 1;
	return (multiplier);
}

void draw(t_data *data)
{
	int i;

	i = 0;
	while (i < WIDTH)
	{
		data->ray.multiplier = discover_multiplier(i);
		data->ray.cam_pix.x = data->player.plane.x * data->ray.multiplier;
		data->ray.cam_pix.y = data->player.plane.y * data->ray.multiplier;
	    data->ray.dir.x = data->player.dir.x + data->ray.cam_pix.x;
		data->ray.dir.y = data->player.dir.y + data->ray.cam_pix.y;
		data->map->x = (int)data->player.pos.x;
		data->map->y = (int)data->player.pos.y;
		data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
		data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);
		dist_to_side(data);
		i++;
	}
}
