/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:49:19 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/24 02:53:09 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_collision(t_data *d, double x, double y)
{
	if (x < 0 || x > ft_strlen(d->map->map[(int)y]) || y < 0 || \
	y > ft_strlen_matrix(d->map->map) || d->map->map[(int)y][(int)x] == '1')
		return (true);
	return (false);
}

void	rotate_player(t_data *d)
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

void	pixel_added(t_data *d)
{
	d->text.size = SPRITE_SIZE;
	d->text.x = (int)(d->ray.wall_x * d->text.size);
	if ((d->ray.hit_side == false && d->ray.dir.x < 0)
		|| (d->ray.hit_side == true && d->ray.dir.y > 0))
		d->text.x = d->text.size - d->text.x - 1;
	d->text.step = 1.0 * d->text.size / d->ray.line_height;
	d->text.pos = (d->ray.start_line - HEIGHT / 2 + d->ray.line_height / 2)
		* d->text.step;
}
