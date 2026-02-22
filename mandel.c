/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:05:08 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/22 17:25:35 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	open_window(t_data *img)
{
    img->mlx = mlx_init();
    img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "fractol");
    img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bpp,
                                 &img->line_len, &img->endian);
}

void draw_pixel(t_data *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

int mandelbrot(double c_re, double c_im, int max_iter)
{
    double z_re = 0, z_im = 0;
    int i = 0;
    double tmp;

    while (z_re * z_re + z_im * z_im <= 4 && i < max_iter)
    {
        tmp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = tmp;
        i++;
    }
    return i;
}
