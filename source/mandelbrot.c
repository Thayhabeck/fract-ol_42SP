/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:46:31 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 22:01:53 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(double x, double y, t_img *img)
{
	double	zx;
	double	zy;
	double	temp;
	int		iteration;

	iteration = 0;
	zx = x;
	zy = y;
	while ((iteration <= img->max_iter) && (zx * zx) + (zy * zy) <= 4)
	{
		temp = zx;
		zx = zx * zx - zy * zy + x;
		zy = 2 * temp * zy + y;
		iteration++;
	}
	return (iteration);
}
