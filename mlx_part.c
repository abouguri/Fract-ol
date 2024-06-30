#include "fractol.h"

int close_prog(t_fractol*fract)
{
    mlx_destroy_image(fract->mlx, fract->img);
    exit(0);
    return (0);
}

void init_image(t_fractol *fract)
{
    fract->img = mlx_new_image(fract->mlx, fract->width, fract->height);
    fract->addr = mlx_get_data_addr(fract->img, &fract->bpp, &fract->size_line, &fract->endian);
}

void	my_mlx_pixel_put(t_fractol *fract, int x, int y, int color)
{
	char	*dst;

	dst = fract->addr + y * fract->size_line + x * (fract->bpp / 8);
	*(unsigned int*)dst = color;
}