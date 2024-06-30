#include "fractol.h"

long double ft_atold_1(long double res, int sign, char* num)
{
    long double decimal;
    long double mult;
    size_t i;

    i = 0;
    decimal = 0;
    mult = 0.1f;
    while (num && num[i] >= '0' && num[i] <= '9')
    {
        decimal = (decimal) + ((num[i] - '0') * mult);
        i++;
        mult /= 10.0f;
    }
    return (res + decimal) * sign;
}

long double ft_atold(char*num)
{
    long double res;
    int sign;
    size_t i;

    i = 0;
    sign = 1;
    res = 0;
    if (num && (num[i] == '-' || num[i] == '+'))
    {
        if (num[i] == '-')
            sign = -1;
        i++;
    }
    while (num && num[i] >= '0' && num[i] <= '9')
    {
        res = (res * 10) + (num[i] - '0');
        i++;
    }
    if (num[i] == '.')
        return ft_atold_1(res, sign, num + i + 1);
    return res * sign;    
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (s1 && s2)
        return s1[i] - s2[i];
    return 1;
}
void    ft_putstr_fd(char *s, int fd)
{
        while (fd >= 0 && s && *s)
        {
                write(fd, s, 1);
                s++;
        }
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}