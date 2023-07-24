/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:48:26 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/24 01:42:21 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_dda(t_data *data)
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

void	dist_to_side(t_data *data)
{
	if (data->ray.dir.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.dist_to_side.x = (data->player.pos.x - data->ray.map.x)
			* data->ray.delta_dist.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.dist_to_side.x = (data->ray.map.x + 1.0 - data->player.pos.x)
			* data->ray.delta_dist.x;
	}
	if (data->ray.dir.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.dist_to_side.y = (data->player.pos.y - data->ray.map.y)
			* data->ray.delta_dist.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.dist_to_side.y = (data->ray.map.y + 1.0 - data->player.pos.y)
			* data->ray.delta_dist.y;
	}
}

void	perform_dda(t_data *data, t_ray *ray)
{
	while (true)
	{
		if (ray->dist_to_side.x < ray->dist_to_side.y)
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
		if (ray->map.y < 0 || ray->map.x < 0 || !data->map->map[ray->map.y]
			|| !data->map->map[ray->map.y][ray->map.x])
			break ;
		if (data->map->map[ray->map.y][ray->map.x] == '1')
			break ;
	}
}

void	calc_line_heigh(t_ray *ray, t_player *player)
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

int	draw(t_data *data)
{
	int	i;

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
