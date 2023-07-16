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
		if (data->ray.hit_side == 0)
			my_mlx_pixel_put(&data->mlx, i, y, 8388608);
		else
			my_mlx_pixel_put(&data->mlx, i, y, 16711680);
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

	i = START_OF_MAP;
	while (i < ft_strlen_matrix(data->map->lines + 6) + 6)
	{
		j = 0;
		while (j < ft_line_len(data->map->lines + 6))
		{
			x = j * 4;
			y = i * 4;
			if (data->map->lines[i][j] == '1')
				draw_square(&data->mlx, x, y, 4, 0x00FF00);
			else if (data->map->lines[i][j] != '\0')
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

