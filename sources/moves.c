#include "../includes/cub3d.h"

int	rotate(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = old_x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
	return (EXIT_SUCCESS);
}

int key_pressed_down(int key, t_data *d)
{
    if (key == XK_w)
    {
        if (d->map->map[(int)d->player.pos.y + 1][(int)d->player.pos.x] != '1')
            d->player.move.y = 1;
    }
    if (key == XK_s)
    {
        if (d->map->map[(int)d->player.pos.y - 1][(int)d->player.pos.x] != '1')
            d->player.move.y = -1;
    }
    if (key == XK_d)
    {
        if (d->map->map[(int)d->player.pos.y][(int)d->player.pos.x + 1] != '1')
            d->player.move.x = -1;
    }
    if (key == XK_a)
    {
        if (d->map->map[(int)d->player.pos.y][(int)d->player.pos.x - 1] != '1')
            d->player.move.x = 1;
    }
    if (key == XK_Right)
    {
        rotate(&d->player.dir.x, &d->player.dir.y, ROT_SPEED);
        rotate(&d->player.plane.x, &d->player.plane.y, ROT_SPEED);
    }
    if (key == XK_Left)
    {
        rotate(&d->player.dir.x, &d->player.dir.y, -ROT_SPEED);
        rotate(&d->player.plane.x, &d->player.plane.y, -ROT_SPEED);
    }
    if (key == XK_Escape)
		ft_close(d);
    return (0);
}

int key_no_pressed(int key, t_data *d)
{
    if (key == XK_w || key == XK_s)
    {
        d->player.move.y = 0;
    }
    if (key == XK_a || key == XK_d)
    {
        d->player.move.x = 0;
    }
    return(0);
}