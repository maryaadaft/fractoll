/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:25:45 by maryaada          #+#    #+#             */
/*   Updated: 2026/04/20 16:47:14 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_julia(t_fractol *julia_img, char **argv)
{
	double	real;
	double	imag;

	real = ft_atof(argv[2]);
	imag = ft_atof(argv[3]);
	if (real < -2.0 || real > 2.0 || imag < -2.0 || imag > 2.0)
		print_error("Error: Julia parameters must be between -2.0 and 2.0\n");
	julia_img->fractal_type = 1;
	julia_img->julia_re = real;
	julia_img->julia_im = imag;
	julia_img->min_re = -2.0;
	julia_img->max_re = 2.0;
	julia_img->min_im = -2.0;
	julia_img->max_im = 2.0;
}

int	julia(double z_re, double z_im, double c_re, double c_im)
{
	int		i;
	double	tmp;

	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < MAX_ITER)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		i++;
	}
	return (i);
}
