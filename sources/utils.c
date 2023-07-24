/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:49:24 by lsantana          #+#    #+#             */
/*   Updated: 2023/07/23 23:49:25 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	discover_multiplier(int pixel)
{
	double	multiplier;

	multiplier = 2 * pixel / (double)WIDTH - 1;
	return (multiplier);
}

int	set_player_direction(t_player *p, char c)
{
	if (c == 'S')
	{
		p->dir.y = 1;
		p->plane.x = -0.66;
	}
	else if (c == 'N')
	{
		p->dir.y = -1;
		p->plane.x = 0.66;
	}
	else if (c == 'W')
	{
		p->dir.x = -1;
		p->plane.y = -0.66;
	}
	else if (c == 'E')
	{
		p->dir.x = 1;
		p->plane.y = 0.66;
	}
	return (EXIT_SUCCESS);
}

void	disc_player_pos(char **map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
				|| map[y][x] == 'E')
			{
				set_player_direction(player, map[y][x]);
				ft_get_play_ang(map[y][x], player);
				player->pos.x = x + 0.5;
				player->pos.y = y + 0.5;
				map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + \
		x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_mlx_pixel_get(t_img *mlx, int x, int y)
{
	char	*byte;

	byte = mlx->addr + ((y * mlx->line_lenght) + \
		(x * mlx->bits_per_pixel / 8));
	return (*(unsigned int *)byte);
}
