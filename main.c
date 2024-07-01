#include "fractol.h"

void print_usage(char*name)
{
    ft_putstr_fd("Bad arguments.\n", 1);
    ft_putstr_fd("usage:\n", 1);
    ft_putstr_fd(name, 1);
    ft_putstr_fd(" mandelbrot\n", 1);
    ft_putstr_fd(name, 1);
    ft_putstr_fd(" julia [real] [imaginary]\n", 1);
}

int is_valid_float(char*num)
{
    int has_encountred_point;
    size_t i;

    i = 0;
    has_encountred_point = 0;
    if (num && (num[i] == '-' || num[i] == '+'))
        i++;
    while (num && num[i])
    {
        if (!(num[i] == '.' || (num[i] >= '0' && num[i] <= '9')))
            return 0;
        if (num[i] == '.' && has_encountred_point == 0)
            has_encountred_point = 1;            
        else if (num[i] == '.')
            return 0;
        i++;
    }
    if (i > 0)
        return (num[i - 1] >= '0' && num[i - 1] <= '9');
    return 0;
}



int main(int c, char **v)
{
    t_fractol fract;

    parse_arguments(c, v, &fract);
    initialize_fractol(&fract);
    setup_mlx_window(&fract);
    setup_hooks(&fract);
    mlx_loop(fract.mlx);

    return 0;
}

void parse_arguments(int c, char **v, t_fractol *fract)
{
    if (c == 2 && ft_strcmp(v[1], "mandelbrot") == 0)
    {
        fract->fract_type = MANDELBROT;
    }
    else if (c == 4 && ft_strcmp(v[1], "julia") == 0)
    {
        fract->fract_type = JULIA;
        if (is_valid_float(v[2]) == 0 || is_valid_float(v[3]) == 0)
        {
            ft_putendl_fd("Not a valid float.", STDERR_FILENO);
            exit(1);
        }
        fract->julia_c.real = ft_atold(v[2]);
        fract->julia_c.im = ft_atold(v[3]);
    }
    else
    {
        print_usage(v[0]);
        exit(1);
    }
}

void initialize_fractol(t_fractol *fract)
{
    fract->mlx = mlx_init();
    fract->width = 800;
    fract->height = 800;
    fract->zoom = 1;
    fract->x_shift = 0;
    fract->y_shift = 0;

    if (fract->mlx == NULL)
    {
        ft_putendl_fd("MLX INITIALIZATION FAILED!", 2);
        exit(69);
    }
}

void setup_mlx_window(t_fractol *fract)
{
    fract->window = mlx_new_window(fract->mlx, fract->width, fract->height, "Fractol");
    if (fract->window == NULL)
    {
        ft_putendl_fd("WINDOW INITIALIZATION FAILED!", 2);
        exit(69);
    }
    init_image(fract);
}

void setup_hooks(t_fractol *fract)
{
    mlx_hook(fract->window, ON_DESTROY, 0, close_prog, fract);
    mlx_mouse_hook(fract->window, mouse, fract);
    mlx_key_hook(fract->window, keyboard, fract);
    mlx_loop_hook(fract->mlx, drawing, fract);
}