#include "../includes/cub3d.h"

void	ft_get_play_ang(char c, t_player *p)
{
	if (c == 'N')
		p->ang = PI / 2;
	else if (c == 'S')
		p->ang = (PI * 3) / 2;
	else if (c == 'E')
		p->ang = 0;
	else if (c == 'W')
		p->ang = PI;
}

int	ft_set_texture(t_data *d)
{
	d->mlx.no = ft_mlx_texture_get (d->mlx.mlx, d->map->no);
	if (!d->mlx.no)
		return (1);
	d->mlx.so = ft_mlx_texture_get (d->mlx.mlx, d->map->so);
	if (!d->mlx.no)
		return (1);
	d->mlx.we = ft_mlx_texture_get (d->mlx.mlx, d->map->we);
	if (!d->mlx.no)
		return (1);
	d->mlx.ea = ft_mlx_texture_get (d->mlx.mlx, d->map->ea);
	if (!d->mlx.no)
		return (1);
	return (0);
}

t_img	*ft_mlx_texture_get(void *mlx, char *file)
{
	int		tmp;
	t_img	*image;

	image = malloc (sizeof(t_mlx));
	image->img = mlx_xpm_file_to_image(mlx, file, &tmp, &tmp);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_lenght, &image->endian);
	return (image);
}



// West é esquerda
// East é direita

int get_direction(t_data *d)
{
	if (d->ray.hit_side == 0)
	{
		if (d->ray.dir.x < 0)
			return (4); //west
		else
			return (2); //east
	}
	else
	{
		if (d->ray.dir.y > 0)
			return (1); //south
		else
			return (3); //north
	}
}