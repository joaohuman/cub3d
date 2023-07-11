#include "../includes/cub3d.h"

int	desenhar(t_data *d)
{
	mlx_loop_hook(d->mlx.mlx, draw, d);
	return (0);
}

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

int	main(int argc, char *argv[])
{
	t_data	data;
	(void)argc;
	(void)argv;
	if (check_errors(argc, argv))
		return (-1);
	init_data(&data);
	//ft_bzero(&data, sizeof(t_data));
	data.map->fd = open(argv[1], O_RDWR);
	if (check_map(data.map))
		return (-1);
	init_mlx(&data.mlx);
	desenhar(&data);
	mlx_hook(data.mlx.win, 02, 1L << 0, &key_pressed, &data);
	mlx_hook(data.mlx.win, 17, 1L << 2, &ft_close, &data);
	mlx_loop(data.mlx.mlx);
	free_all(&data);
	return (0);
}
