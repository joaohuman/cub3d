#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_errors(argc, argv))
		return (-1);
	init_data(&data);
	data.map->fd = open(argv[1], O_RDWR);
	if (check_map(data.map))
	{
		free_all(&data);
		return (-1);
	}
	free_all(&data);
	// teste.mlx = mlx_init();
	// teste.win = mlx_new_window(teste.mlx, 600, 600, "Hello world!");
	// mlx_key_hook(teste.win, key_hook, &teste);
	// mlx_loop(teste.mlx);
	return (0);
}
