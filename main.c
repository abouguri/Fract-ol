/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouguri <abouguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:53:34 by abouguri          #+#    #+#             */
/*   Updated: 2024/05/15 11:54:19 by abouguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    add_complex(t_complex *n1, t_complex n2)
{
    n1->real = n1->real + n2.real;
    n1->im = n1->im + n2.im;
}

void    squ_complex(t_complex *n)
{
    double tmp;
    tmp = n->real;
    n->real = (tmp * tmp) - (n->im * n->im);
    n->im = 2 * tmp * n->im;
}

void init_image(t_fractol *fract)
{
    fract->img = mlx_new_image(fract->mlx, fract->width, fract->height);
    fract->addr = mlx_get_data_addr(fract->img, &fract->bpp, &fract->size_line, &fract->endian);
}

double  map(double x, double xm, double out_min, double out_max)
{
    return (((x / xm) * out_max) + (((xm - x) / xm) * out_min));
}

void	my_mlx_pixel_put(t_fractol *fract, int x, int y, int color)
{
	char	*dst;

	dst = fract->addr + y * fract->size_line + x * (fract->bpp / 8);
	*(unsigned int*)dst = color;
}

void draw_mandelbrot(t_fractol *fract)
{
    t_complex c;
    t_complex z;
    int i;
    for (size_t y = 0; y < fract->height; y++)
    {
        for (size_t x = 0; x < fract->width; x++)
        {
            c.real = map(x,fract->width, -2, 2);
            c.im = map(y,fract->height, -2, 2);
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
                my_mlx_pixel_put(fract, x, y, 0x00FFFFFF);
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
    draw_mandelbrot(fract);

    return 0;
}

int mouse(int button, int x, int y, t_fractol *fract)
{
    (void)fract;
    printf("button = %d, x = %d, y = %d\n", button, x, y);
    return (0);
}

int main(int c, char**v)
{
    (void)c;
    (void)v;
    t_fractol fract;

    fract.mlx = mlx_init();
    fract.width = 800;
    fract.height = 800;
    if (fract.mlx == NULL)
    {
        ft_putendl_fd("MLX INITIALIZATION FAILED!", 2);
        exit(69);
    }
    fract.window = mlx_new_window(fract.mlx, fract.width, fract.height, "Fractol");
    if (fract.window == NULL)
    {
        ft_putendl_fd("WINDOW INITIALIZATION FAILED!", 2);
        exit(69);
    }
    init_image(&fract);
    mlx_mouse_hook(fract.window, mouse, &fract);
    mlx_loop_hook(fract.mlx, drawing, &fract);
    mlx_loop(fract.mlx);
    return 0;
}