#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_mlx	teste;

	//if (check_errors(argc, argv))
	//	return (-1);
	(void)argc;
	(void)argv;
	init_window(&teste);
	my_mlx_pixel_put(teste.mlx, 50, 50, 0x000000);
	mlx_put_image_to_window(teste.mlx, teste.win, teste.img, 0, 0);
	mlx_loop(teste.mlx);
	return (0);
}

char *get_next_line(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}

void	init_window(t_mlx *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		exit (1);
	f->win = mlx_new_window(f->mlx, 600, 600, "CUB3D");
	f->img = mlx_new_image(f->mlx, 600, 600);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_lenght, \
	&f->endian);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * \
	(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}