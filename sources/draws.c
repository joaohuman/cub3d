#include "../includes/cub3d.h"

void draw_image(t_data *data, int i)
{
	int y;

	y = 0;
	while(y < data->ray.start_line)
	{
		my_mlx_pixel_put(&data->mlx, i, y, data->map->ceil);
		y++;
	}
	while (y < data->ray.end_line)
	{
		data->text.y = (int)data->text.pos & (data->text.size - 1);
		data->text.pos += data->text.step;
		if (get_direction(data) == SO)
			my_mlx_pixel_put(&data->mlx, i, y, ft_mlx_pixel_get(data->mlx.so, data->text.x, data->text.y)); // azul
		else if (get_direction(data) == WE)
			my_mlx_pixel_put(&data->mlx, i, y, ft_mlx_pixel_get(data->mlx.we, data->text.x, data->text.y));
		else if (get_direction(data) == NO)
			my_mlx_pixel_put(&data->mlx, i, y, ft_mlx_pixel_get(data->mlx.no, data->text.x, data->text.y)); // ciano
		else if (get_direction(data) == EA)
			my_mlx_pixel_put(&data->mlx, i, y, ft_mlx_pixel_get(data->mlx.ea, data->text.x, data->text.y)); // verde
		y++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(&data->mlx, i, y, data->map->floor);
		y++;
	}
}

void draw_minimapa(t_data *data)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i < ft_strlen_matrix(data->map->map))
	{
		j = 0;
		while (j < (int)ft_strlen(data->map->map[i]))
		{
			x = j * 4;
			y = i * 4;
			if (data->map->map[i][j] == '1')
				draw_square(&data->mlx, x, y, 4, 0x00FF00);
			else if (data->map->map[i][j] != '\0')
				draw_square(&data->mlx, x, y, 4, 0x000000);
			j++;
		}
		i++;
	}
	draw_square(&data->mlx, data->player.pos.x * 4, data->player.pos.y * 4, 4, 0xFF0000);
}

void draw_square(t_mlx *mlx, int x, int y, int size, int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(mlx, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
