/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:25:45 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/22 17:26:03 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

