#include "../includes/cub3d.h"

int	key_hook(int keycode, t_mlx *vars)
{
	(void)vars;
	printf("%d\n", keycode);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	teste;

	//if (check_errors(argc, argv))
	//	return (-1);
	(void)argc;
	(void)argv;
	teste.mlx = mlx_init();
	teste.win = mlx_new_window(teste.mlx, 600, 600, "Hello world!");
	mlx_key_hook(teste.win, key_hook, &teste);
	mlx_loop(teste.mlx);
	return (0);
}

char *get_next_line(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}
