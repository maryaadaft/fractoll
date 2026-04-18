/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:40:46 by maryaada          #+#    #+#             */
/*   Updated: 2026/04/18 18:46:47 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (((unsigned char)s1[i] || (unsigned char)s2[i]))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			return (1);
		}
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

void	print_error(char *error_msg)
{
	int i;

	i = 0;
	while (error_msg[i] != '\0')
	{
		write(2, &error_msg[i], 1);
		i++;
	}
	exit(1);
}
