#include "fractol.h"

void draw_mandelbrot(t_fractol *fract)
{
    t_complex c;
    t_complex z;
    int i;
    for (size_t y = 0; y < fract->height; y++)
    {
        for (size_t x = 0; x < fract->width; x++)
        {
            c.real = map(x,fract->width, (-2 +fract->x_shift) * fract->zoom, (2 +fract->x_shift) * fract->zoom);
            c.im = map(y,fract->height, (-2 +fract->y_shift) * fract->zoom, (2+fract->y_shift) * fract->zoom);
            z = c;
            i = 1;
            while(i < ITERATION)
            {
                squ_complex(&z);
                add_complex(&z, c);
                if ((z.im * z.im) + (z.real * z.real) > 4)
                    break;
                i++;
            }
            if ((z.im * z.im) + (z.real * z.real) > 4)
            {
                unsigned char r = 0xFF / 2*i;
                unsigned char g = 0xFF / 3/i;
                unsigned char b = 0xFF / 5*i;
                int c =  (r << 16) | (g << 8) | b;
                my_mlx_pixel_put(fract, x, y, c);
            }
            else
            {
                my_mlx_pixel_put(fract, x, y, BLACK);
            }   
        }
    }
    mlx_put_image_to_window(fract->mlx, fract->window, fract->img, 0, 0);
}

void draw_julia(t_fractol *fract)
{
    t_complex c;
    t_complex z;
    int i;
    for (size_t y = 0; y < fract->height; y++)
    {
        for (size_t x = 0; x < fract->width; x++)
        {
            c.real = map(x,fract->width, (2 +fract->x_shift) * fract->zoom, (-2 +fract->x_shift) * fract->zoom);
            c.im = map(y,fract->height, (-2 +fract->y_shift) * fract->zoom, (2+fract->y_shift) * fract->zoom);
            z = c;
            i = 1;
            while(i < ITERATION)
            {
                squ_complex(&z);
                add_complex(&z, fract->julia_c);
                if ((z.im * z.im) + (z.real * z.real) > 4)
                    break;
                i++;
            }
            if ((z.im * z.im) + (z.real * z.real) > 4)
            {
                int color = 0x00404060;
                int c = map(i, ITERATION, color - 1200,  color);
                my_mlx_pixel_put(fract, x, y, c);
            }
            else
            {
                my_mlx_pixel_put(fract, x, y, 0);
            }   
        }
    }
    mlx_put_image_to_window(fract->mlx, fract->window, fract->img, 0, 0);
}

int drawing(t_fractol *fract)
{
    if (fract->fract_type == MANDELBROT)
        draw_mandelbrot(fract);
    else if (fract->fract_type)
        draw_julia(fract);
    return 0;
}