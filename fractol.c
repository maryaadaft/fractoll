/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:20:19 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/22 21:54:52 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_args(char **argv, int argc, t_fractol *img)
{
	if ((argc == 2 || argc == 4) && ft_strcmp(argv[1], "Julia") == 0)
	{
		if ((argc == 2) &&  ft_strcmp(argv[1], "Julia") == 0)
		{
			write(1, "Please add the 2 Julia values!!!", 33);
			return ;
		}
		else
		{
			choose_julia(img, argv);
			return ;
		}
	}
	else if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		choose_mandel(img);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_fractol img;

	if (argc >= 2 && argc <= 4)
		handle_args(argv, argc, &img);
	else
		write(1, "Choose to run \n ./fractol Mandelbrot \n OR \n ./fractol Julia <real> <imagi>\n", 75);
		
	open_window(&img);
	int y = 0;
	while(y < HEIGHT)
	{
		int x = 0;
		while (x < WIDTH)
		{
			draw_pixel(&img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}

//convert x and y into real and imaginary numbers
/* 
double pixel_to_real(int x, t_fractol *f)
{
    return f->min_re + x * (f->max_re - f->min_re) / f->width;
}

double pixel_to_imag(int y, t_fractol *f)
{
    return f->min_im + y * (f->max_im - f->min_im) / f->height;
}

 */

 //=============================================================
 
// rendering a fractol any one of them
/* void render(t_fractol *f)
{
    int x, y, iter;
    double re, im;
    int color;

    for (y = 0; y < f->height; y++)
    {
        for (x = 0; x < f->width; x++)
        {
            re = pixel_to_real(x, f);
            im = pixel_to_imag(y, f);
            if (f->fractal_type == 0)
                iter = mandelbrot(re, im, f->max_iter);
            else
                iter = julia(re, im, f->julia_c_re, f->julia_c_im, f->max_iter);

            color = (iter << 21) | (iter << 10) | iter*8; // simple coloring
            draw_pixel(&f->img, x, y, color);
        }
    }
    mlx_put_image_to_window(f->img.mlx, f->img.win, f->img.img, 0, 0);
}
 */
