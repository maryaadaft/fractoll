/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:26:12 by maryaada          #+#    #+#             */
/*   Updated: 2026/04/20 16:56:19 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	open_window(t_fractol *img)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		print_error("Error: MLX initialization failed\n");
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "fractol");
	if (!img->win)
	{
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		print_error("Error: could not create window..\n");
	}
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	if (!img->img)
	{
		mlx_destroy_window(img->mlx, img->win);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		print_error("Error: Image creation failed\n");
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	if (!img->addr)
	{
		write(2, "Error: Image address retrieval failed\n", 39);
		close_handler(img);
	}
}

void	draw_pixel(t_fractol *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (BLACK);
	t = (double)iter / MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

void	render(t_fractol *img)
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = img->min_re + (double)x / WIDTH * (img->max_re - img->min_re);
			ci = img->max_im - (double)y / HEIGHT * (img->max_im - img->min_im);
			if (img->fractal_type == 0)
				iter = mandelbrot(cr, ci);
			else
				iter = julia(cr, ci, img->julia_re, img->julia_im);
			draw_pixel(img, x, y, get_color(iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int	close_handler(t_fractol *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(0);
}
