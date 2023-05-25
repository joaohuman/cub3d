#include "../includes/cub3d.h"

int	key_hook(int keycode, t_mlx *vars)
{
	(void)vars;
	printf("%d\n", keycode);
	return (0);
}

int	check_map(t_map *map)
{
	char *line;
	// char *aux;

	printf("teste\n");
	printf("%i\n", map->fd);
	line = get_next_line(map->fd);
	printf("teste\n");
	// aux = line;
	// if (line == NULL)
	// 	return(-1);
	// while (aux)
	// {
	// 	printf("line: %s\n", line);
	// 	printf("aux: %s\n", line);
	// 	aux = get_next_line(map->fd);
	// 	line = ft_strjoin(line, aux);
	// 	// free(aux);
	// }
	return (0);
}

void	init_texture(t_texture *tex)
{
	tex->no = 0;
	tex->so = 0;
	tex->we = 0;
	tex->ea = 0;
	tex->floor = 0;
	tex->ceil = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = 0;
	mlx->win = 0;
	mlx->img = 0;
	mlx->addr = 0;
	mlx->bits_per_pixel = 0;
	mlx->line_lenght = 0;
	mlx->endian = 0;
	mlx->set = 0;
}

void	init_map(t_map *map)
{
	map->lines = 0;
	map->fd = 0;
}

void	init_data(t_data *data)
{
	data->tex = malloc(sizeof(t_texture));
	data->mlx = malloc(sizeof(t_mlx));
	data->map = malloc(sizeof(t_map));

	init_texture(data->tex);
	init_mlx(data->mlx);
	init_map(data->map);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	// if (check_errors(argc, argv))
	// 	return (-1);
	(void)argc;
	(void)argv;
	(void)data;
	init_data(&data);
	data.map->fd = open(argv[1], O_RDONLY);
	if (check_map(data.map))
		return (-1);
	// teste.mlx = mlx_init();
	// teste.win = mlx_new_window(teste.mlx, 600, 600, "Hello world!");
	// mlx_key_hook(teste.win, key_hook, &teste);
	// mlx_loop(teste.mlx);
	return (0);
}
