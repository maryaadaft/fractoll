/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:20:19 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/22 17:27:40 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_args(char **argv, int argc)
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
			write(1, "Julia Selected!", 16);
			return ;
		}
	}
	else if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		write(1, "Mandelbrot Selected\n", 20);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_data img;

	if (argc >= 2 && argc <= 4)
	{
		handle_args(argv, argc);
	}
	else
		write(1, "no arguments or too many arguments inputted", 34);
		
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
// rendering a fractol
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

/* 
int main(void)
{
    t_data img;

    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "fractol");
    img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bpp,
                                 &img.line_len, &img.endian);

    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    mlx_loop(img.mlx);
}
 */