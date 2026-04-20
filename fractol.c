/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:20:19 by maryaada          #+#    #+#             */
/*   Updated: 2026/04/20 17:21:34 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_help(void)
{
	write(1, "=--------------------------------------=\n", 42);
	write(1, "         >>How to run:<<\n", 26);
	write(1, "  ./fractol Mandelbrot\n", 24);
	write(1, "  ./fractol Julia <real> <imaginary>\n", 37);
	write(1, "\n       >>Julia Examples:<<\n", 29);
	write(1, "  ./fractol Julia -0.8 0.156\n", 29);
	write(1, "  ./fractol Julia -0.7 0.7\n", 28);
	write(1, "  ./fractol Julia 0.285 0.01\n", 30);
	write(1, "Parameters must be between -2.0 and 2.0\n", 41);
	write(1, "=--------------------------------------=\n", 42);
	exit(1);
}

void	handle_args(char **argv, int argc, t_fractol *img)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 && argc == 2)
	{
		choose_mandel(img);
		return ;
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		if (argc != 4)
			print_error("Error: Julia needs exactly 2 parameters\n");
		if (argc == 4 && !(ft_isnum(argv[2]) && ft_isnum(argv[3])))
			print_error("Error: Julia numbers must be between -2 and 2\n");
		choose_julia(img, argv);
		return ;
	}
	else
		print_help();
}

int	main(int argc, char **argv)
{
	t_fractol	img;

	if (argc < 2)
		print_help();
	handle_args(argv, argc, &img);
	open_window(&img);
	render(&img);
	mlx_key_hook(img.win, key_handler, &img);
	mlx_mouse_hook(img.win, mouse_handler, &img);
	mlx_hook(img.win, 17, 0, close_handler, &img);
	mlx_loop(img.mlx);
	return (0);
}
