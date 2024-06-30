#include "fractol.h"

int mouse(int button, int x, int y, t_fractol *fract)
{
    (void)fract;
    printf("button = %d, x = %d, y = %d\n", button, x, y);
    if (button == 5)
    {
        fract->zoom += 0.1f;
    }
    else if (button == 4)
    {
        if (fract->zoom > 0.1f)
            fract->zoom -= 0.1f;
    }
    return (0);
}

int keyboard(int button, t_fractol *fract)
{
    (void)fract;

    if (button == 65364)
    {
        fract->y_shift -= 0.1f;
    }
    else if (button == 65362)
    {
        fract->y_shift += 0.1f;
    }
    else if (button == 65361)
    {
        fract->x_shift += 0.1f;
    }
    else if (button == 65363)
    {
        fract->x_shift -= 0.1f;
    }
    else if (button == 65307)
    {
        mlx_destroy_window(fract->mlx, fract->window);
        close_prog(fract);
    }
    return (0);
}