/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:05:08 by maryaada          #+#    #+#             */
/*   Updated: 2026/04/20 16:48:53 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_mandel(t_fractol *mandel_img)
{
	mandel_img->fractal_type = 0;
	mandel_img->min_re = -2.0;
	mandel_img->max_re = 1.0;
	mandel_img->min_im = -1.5;
	mandel_img->max_im = 1.5;
}

int	mandelbrot(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	z_re = 0.0;
	z_im = 0.0;
	i = 0;
	while (z_re * z_re + z_im * z_im <= 4.0 && i < MAX_ITER)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		i++;
	}
	return (i);
}
