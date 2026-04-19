/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:24:03 by maryaada          #+#    #+#             */
/*   Updated: 2026/04/20 00:56:07 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isnum(const char *s)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (!s || !s[0])
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

double	ft_atof(const char *s)
{
	double	result;
	double	frac;
	int		sign;
	int		i;

	if (!ft_isnum(s))
		print_error("Error: Julia numbers must be between -2 and 2\n");
	result = 0.0;
	frac = 1.0;
	sign = 1;
	i = 0;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
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
