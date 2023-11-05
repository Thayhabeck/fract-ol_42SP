/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:46:34 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 22:01:58 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia(double x, double y, t_img *img)
{
	double	zx;
	double	zy;
	double	temp;
	int		iteration;

	iteration = 0;
	zx = x;
	zy = y;
	while ((iteration < img->max_iter) && (zx * zx) + (zy * zy) <= 4)
	{
		temp = zx;
		zx = zx * zx - zy * zy + img->julia_x;
		zy = 2 * temp * zy + img->julia_y;
		iteration++;
	}
	return (iteration);
}
