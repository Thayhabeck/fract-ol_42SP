/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starjulia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 02:29:27 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 22:02:10 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	starjulia(double x, double y, t_img *img)
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
		temp = pow(zx, 5) - 10 * pow(zx, 3) * zy * zy + 5 * zx * pow(zy, 4);
		zy = 5 * pow(zx, 4) * zy - 10 * zx * zx * pow(zy, 3) + pow(zy, 5);
		zx = temp + img->julia_x;
		zy += img->julia_y;
		iteration++;
	}
	return (iteration);
}
