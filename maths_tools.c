#include "fractol.h"


void    add_complex(t_complex *n1, t_complex n2)
{
    n1->real = n1->real + n2.real;
    n1->im = n1->im + n2.im;
}

void    squ_complex(t_complex *n)
{
    long double tmp;
    tmp = n->real;
    n->real = (tmp * tmp) - (n->im * n->im);
    n->im = 2 * tmp * n->im;
}

long double  map(long double x, long double xm, long double out_min, long double out_max)
{
    return (((x / xm) * out_max) + (((xm - x) / xm) * out_min));
}
