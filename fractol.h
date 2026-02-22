/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:53:53 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/22 17:24:49 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define	FRACTOL_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "mlx/mlx.h"

//window size
#define WIDTH 600
#define HEIGHT 600

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_data;

typedef struct s_fractol
{
    t_data img;
    int width;
    int height;
    double min_re;
    double max_re;
    double min_im;
    double max_im;
    int max_iter;
    int fractal_type; // 0 = Mandelbrot, 1 = Julia
    double julia_c_re;
    double julia_c_im;
    double zoom;
    double move_x;
    double move_y;
} t_fractol;


int	ft_strcmp(const char *s1, const char *s2);
void	open_window(t_data *img);
void draw_pixel(t_data *img, int x, int y, int color);


#endif