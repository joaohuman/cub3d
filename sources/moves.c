#include "../includes/cub3d.h"

//rotate(&d->player.plane_x, &d->player.plane_y, -ROTSPEED);

int	rotate(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = old_x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
    printf("old_x: %f, x: %f, y: %f\n", old_x, *x, *y);
	return (EXIT_SUCCESS);
}

int key_pressed_down(int key, t_data *d)
{
    if (key == XK_w)
    {
        d->player.move.y = 1;
    }
    else if (key == XK_s)
    {
        d->player.move.y = -1;
    }
    else if (key == XK_a)
    {
        d->player.move.x = -1;
    }
    else if (key == XK_d)
    {
        d->player.move.x = 1;
    }
    return (0);
}

int key_no_pressed(int key, t_data *d)
{
    if (key == XK_w)
    {
        d->player.move.y = 0;
    }
    else if (key == XK_s)
    {
        d->player.move.y = 0;
    }
    else if (key == XK_a)
    {
        d->player.move.x = 0;
    }
    else if (key == XK_d)
    {
        d->player.move.x = 0;
    }
    return(0);
}