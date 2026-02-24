/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:24:03 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/24 16:24:13 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double    ft_atof(const char *s)
{
    double  result;
    double  frac;
    int     sign;
    int     i;

    result = 0.0;
    frac = 1.0;
    sign = 1;
    i = 0;
    if (s[i] == '-' && ++i)
        sign = -1;
    while (s[i] >= '0' && s[i] <= '9')
        result = result * 10 + (s[i++] - '0');
    if (s[i] == '.')
        i++;
    while (s[i] >= '0' && s[i] <= '9')
    {
        frac /= 10.0;
        result += (s[i++] - '0') * frac;
    }
    return (result * sign);
}
