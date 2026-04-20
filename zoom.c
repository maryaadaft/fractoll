/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:37:04 by maryaada          #+#    #+#             */
/*   Updated: 2026/04/20 16:57:27 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *img, double factor)
{
	double	center_re;
	double	center_im;

	center_re = (img->min_re + img->max_re) / 2;
	center_im = (img->min_im + img->max_im) / 2;
	img->min_re = center_re + (img->min_re - center_re) * factor;
	img->max_re = center_re + (img->max_re - center_re) * factor;
	img->min_im = center_im + (img->min_im - center_im) * factor;
	img->max_im = center_im + (img->max_im - center_im) * factor;
	render(img);
}

int	key_handler(int keycode, t_fractol *img)
{
	if (keycode == KEY_ESC)
		close_handler(img);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *img)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom(img, 0.8);
	else if (button == 5)
		zoom(img, 1.2);
	return (0);
}
