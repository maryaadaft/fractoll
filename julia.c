/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:25:45 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/22 21:57:42 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_julia(t_fractol *julia_img, char **argv)
{
	(void)argv;
	write(1, "Julia Selected\n", 15);
	julia_img->fractal_type = 1;
	// julia_img->julia_re = ft_atof(argv[2]); //remake atoi to handle doubles
	// julia_img->julia_im = ft_atof(argv[3]);
	julia_img->min_re = -2.0;
	julia_img->max_re = 2.0;
	julia_img->min_im = -2.0;
	julia_img->max_im = 2.0;
}

int julia(double z_re, double z_im, double c_re, double c_im, int max_iter)
{
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

