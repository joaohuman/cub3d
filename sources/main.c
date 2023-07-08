#include "../includes/cub3d.h"

int	desenhar(t_data *d)
{
	mlx_loop_hook(d->mlx.mlx, draw, d);
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

	mlx_loop(data.mlx.mlx);
	free_all(&data);
	return (0);
}
