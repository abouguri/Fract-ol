/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouguri <abouguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:53:14 by abouguri          #+#    #+#             */
/*   Updated: 2024/05/15 11:53:15 by abouguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#define ITERATION 20

typedef struct s_fractol {
    void *mlx;
    void *window;
    size_t width;
    size_t height;
    void *img;
    char *addr;
    int bpp;
    int size_line;
    int endian;
} t_fractol;

typedef struct s_complex {
    double real;
    double im;
} t_complex;

void	ft_putendl_fd(char *s, int fd);
void    ft_putstr_fd(char *s, int fd);
void    add_complex(t_complex *n1, t_complex n2);
void    squ_complex(t_complex *n);

#endif