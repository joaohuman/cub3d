#include "../includes/cub3d.h"

int	ft_close(t_data *s)
{
	mlx_destroy_image(s->mlx.mlx, s->mlx.img);
	mlx_destroy_window(s->mlx.mlx, s->mlx.win);
	mlx_destroy_display(s->mlx.mlx);
	free(s->mlx.mlx);
	exit (0);
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

	y = START_OF_MAP;
	x = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == 'N' || map[y][x] == 'S' || \
			map[y][x] == 'W' || map[y][x] == 'E')
			{
				player->pos.x = x + 0.5;
				player->pos.y = y + 0.5;
				set_player_direction(player, map[y][x]);
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

int ft_line_len(char **map)
{
	int i;
	size_t len;

	i = 0;
	len = 0;
	while(map[i])
	{
		if (ft_strlen(map[i]) > len)
			len = ft_strlen(map[i]);
		i++;
	}
	return ((int)len + 1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	(void)argc;
	(void)argv;
	if (check_errors(argc, argv))
		return (-1);
	init_data(&data);
	data.map->fd = open(argv[1], O_RDWR);
	if (check_map(data.map))
		return (-1);
	disc_player_pos(data.map->lines, &data.player);
	init_mlx(&data.mlx);
	mlx_loop_hook(data.mlx.mlx, draw, &data);
	mlx_hook(data.mlx.win, 02, 1L<<0, &key_pressed_down, &data);
	mlx_hook(data.mlx.win, 03, 1L<<1, &key_no_pressed, &data);
	mlx_hook(data.mlx.win, 17, 1L<<17, &ft_close, &data);
	mlx_loop(data.mlx.mlx);
	free_all(&data);
	return (0);
}
