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
        d->player.move.y = 1;
    if (key == XK_s)
        d->player.move.y = -1;
    if (key == XK_d)
        d->player.move.x = -1;
    if (key == XK_a)
        d->player.move.x = 1;
    if (key == XK_Right)
        d->player.rotate = 1;
    if (key == XK_Left)
        d->player.rotate = 2;
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
    if (key == XK_Right || key == XK_Left)
    {
        d->player.rotate = 0;
    }
    return(0);
}