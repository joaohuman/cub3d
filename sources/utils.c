#include "../includes/cub3d.h"

double discover_multiplier(int pixel)
{
	double multiplier;

	multiplier = 2 * pixel / (double)WIDTH - 1;
	return (multiplier);
}

int    set_player_direction(t_player *p, char c)
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

void disc_player_pos(char **map, t_player *player)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == 'N' || map[y][x] == 'S' || \
			map[y][x] == 'W' || map[y][x] == 'E')
			{
				set_player_direction(player, map[y][x]);
				player->pos.x = x + 0.5;
				player->pos.y = y + 0.5;
				return;
			}
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * \
	(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}