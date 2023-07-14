#include "../includes/cub3d.h"

int	ft_close(t_data *s)
{
	mlx_destroy_image(s->mlx.mlx, s->mlx.img);
	mlx_destroy_window(s->mlx.mlx, s->mlx.win);
	mlx_destroy_display(s->mlx.mlx);
	free(s->mlx.mlx);
	exit (0);
}

int	key_pressed(int key_code, t_data *s)
{
	if (key_code == ESC)
		ft_close(s);
	return (0);
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
			if(map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
			{
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

	mlx_hook(data.mlx.win, 02, 1L << 0, &key_pressed, &data);
	mlx_hook(data.mlx.win, 17, 1L << 2, &ft_close, &data);
	mlx_loop(data.mlx.mlx);
	free_all(&data);
	return (0);
}
