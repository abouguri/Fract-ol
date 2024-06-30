#ifndef FRACTOL_H
#define FRACTOL_H
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#define ITERATION 70

#define 	ON_KEYDOWN 2
#define 	ON_KEYUP 3
#define 	ON_MOUSEDOWN 4
#define 	ON_MOUSEUP 5
#define 	ON_MOUSEMOVE 6
#define     ON_EXPOSE 12
#define 	ON_DESTROY  17
#define BLACK 0x000000
#define WHITE 0xFFFFFF

typedef enum e_fract_type
{
    MANDELBROT,
    JULIA
} t_fract_type;

typedef struct s_complex {
    long double real;
    long double im;
} t_complex;

typedef struct s_fractol {
    t_fract_type fract_type;
    void *mlx;
    void *window;
    size_t width;
    size_t height;
    void *img;
    char *addr;
    int bpp;
    int size_line;
    int endian;
    long double x_shift;
    long double y_shift;
    long double zoom;
    t_complex julia_c;
} t_fractol;


void	ft_putendl_fd(char *s, int fd);
void    ft_putstr_fd(char *s, int fd);
void    add_complex(t_complex *n1, t_complex n2);
void    squ_complex(t_complex *n);
int ft_strcmp(const char *s1, const char *s2);
long double ft_atold(char*num);
long double ft_atold_1(long double res, int sign, char* num);
int keyboard(int button, t_fractol *fract);
int mouse(int button, int x, int y, t_fractol *fract);
long double  map(long double x, long double xm, long double out_min, long double out_max);
void    squ_complex(t_complex *n);
void    add_complex(t_complex *n1, t_complex n2);
int close_prog(t_fractol *fract);
int ft_strcmp(const char *s1, const char *s2);
void draw_mandelbrot(t_fractol *fract);
void draw_julia(t_fractol *fract);
int drawing(t_fractol *fract);
int close_prog(t_fractol*fract);
void init_image(t_fractol *fract);
void	my_mlx_pixel_put(t_fractol *fract, int x, int y, int color);

#endif