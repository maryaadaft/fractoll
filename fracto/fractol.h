/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:53:53 by maryaada          #+#    #+#             */
/*   Updated: 2026/04/20 17:04:48 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 100
# define KEY_ESC 65307
# define BLACK 0x000000

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		fractal_type;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	julia_re;
	double	julia_im;
}	t_fractol;

int		ft_strcmp(const char *s1, const char *s2);
void	open_window(t_fractol *img);
void	draw_pixel(t_fractol *img, int x, int y, int color);
void	print_error(char *error_msg);
int		ft_isnum(const char *s);
void	choose_mandel(t_fractol *img);
void	choose_julia(t_fractol *img, char **argv);
int		mandelbrot(double c_re, double c_im);
int		get_color(int iter);
void	render(t_fractol *img);
void	zoom(t_fractol *img, double factor);
int		mouse_handler(int button, int x, int y, t_fractol *img);
int		close_handler(t_fractol *img);
int		key_handler(int keycode, t_fractol *img);
int		julia(double z_re, double z_im, double c_re, double c_im);
double	ft_atof(const char *s);

#endif
