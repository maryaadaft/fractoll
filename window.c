/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:26:12 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/24 17:25:37 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	open_window(t_fractol *img)
{
    img->mlx = mlx_init();
    img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "fractol");
    img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bpp,
                                 &img->line_len, &img->endian);
}

void draw_pixel(t_fractol *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

int get_color(int iter)
{
    double t;
    int r;
    int g;
    int b;

    if (iter == MAX_ITER)
        return (0x000000);

    t = (double)iter / MAX_ITER;

    r = (int)(9 * (1 - t) * t * t * t * 255);
    g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (r << 16 | g << 8 | b);
}

void    render(t_fractol *img)
{
    int     x;
    int     y;
    double  cr;
    double  ci;
    int     iter;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            cr = img->min_re + (double)x / WIDTH * (img->max_re - img->min_re);
            ci = img->min_im + (double)y / HEIGHT * (img->max_im - img->min_im);
            if (img->fractal_type == 0)
                iter = mandelbrot(cr, ci);
            else
    			iter = julia(cr, ci, img->julia_re, img->julia_im,
						MAX_ITER);
            draw_pixel(img, x, y, get_color(iter));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int    close_handler(t_fractol *img)
{
    mlx_destroy_image(img->mlx, img->img);
    mlx_destroy_window(img->mlx, img->win);
    mlx_destroy_display(img->mlx);
    free(img->mlx);
    exit(0);
}


// iter = julia(cr, ci, img);