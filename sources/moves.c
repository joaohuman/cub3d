/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:49:07 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/24 02:52:01 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rotate(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = old_x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
	return (EXIT_SUCCESS);
}

int	move(t_data *d, double dx, double dy)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = d->player.pos.x + dx * 0.05;
	new_pos_y = d->player.pos.y + dy * 0.05;
	if (check_collision(d, new_pos_x, new_pos_y + 0.05) || \
	check_collision(d, new_pos_x, new_pos_y - 0.05) || \
	check_collision(d, new_pos_x + 0.05, new_pos_y) || \
	check_collision(d, new_pos_x - 0.05, new_pos_y))
		return (EXIT_FAILURE);
	if (dx != 0 && dy != 0)
	{
		if (check_collision(d, new_pos_x + dx * 0.1, d->player.pos.y)
			|| check_collision(d, d->player.pos.x, new_pos_y + dy * 0.1))
			return (EXIT_FAILURE);
	}
	d->player.pos.x = new_pos_x;
	d->player.pos.y = new_pos_y;
	return (EXIT_SUCCESS);
}

int	key_pressed_down(int key, t_data *d)
{
	if (key == XK_w)
		move(d, d->player.dir.x, d->player.dir.y);
	if (key == XK_s)
		move(d, -d->player.dir.x, -d->player.dir.y);
	if (key == XK_a)
		move(d, -d->player.plane.x, -d->player.plane.y);
	if (key == XK_d)
		move(d, d->player.plane.x, d->player.plane.y);
	if (key == XK_Right)
		d->player.rotate = 1;
	if (key == XK_Left)
		d->player.rotate = 2;
	if (key == XK_Escape)
		ft_close(d);
	return (0);
}

int	key_no_pressed(int key, t_data *d)
{
	if (key == XK_Right || key == XK_Left)
		d->player.rotate = 0;
	return (0);
}
