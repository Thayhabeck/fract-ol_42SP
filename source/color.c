/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:04:58 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 17:48:07 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	bernstein_color(int iteration, t_img *img)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	long double		ni;
	long double		bern_range;

	bern_range = 10 - (long double)img->range;
	ni = ((long double)iteration * bern_range) / (long double)img->max_iter;
	red = 9.0 * (1.0 - ni) * pow(ni, 3.0) * 255.0;
	green = 15.0 * pow((1.0 - ni), 2.0) * pow(ni, 2.0) * 255.0;
	blue = 8.5 * pow((1.0 - ni), 3.0) * ni * 255.0;
	return (red << 16 | green << 8 | blue);
}

void	set_color_bernstein(double x, double y, int iteration, t_img *img)
{
	int			color;

	color = BLACK;
	if (iteration >= img->max_iter)
		color = BLACK;
	else
	color = bernstein_color(iteration, img);
	my_mlx_pixel_put(img, x / img->pass - img->xmin / img->pass, \
	y / img->pass - img->ymin / img->pass, color);
}

void	set_color_pallete(double x, double y, int iteration, t_img *img)
{
	int	color;

	color = BLACK;
	if (iteration >= img->max_iter)
		color = BLACK;
	else if ((iteration / img->range) % 5 == 1)
		color = DYE1;
	else if ((iteration / img->range) % 5 == 2)
		color = DYE2;
	else if ((iteration / img->range) % 5 == 3)
		color = DYE3;
	else if ((iteration / img->range) % 5 == 4)
		color = DYE4;
	else if ((iteration / img->range) % 5 == 0)
		color = DYE5;
	my_mlx_pixel_put(img, x / img->pass - img->xmin / img->pass, \
	y / img->pass - img->ymin / img->pass, color);
}

void	set_color(double x, double y, int i, t_img *img)
{
	if (img->color == BLUE_CODE || img->color == GREEN_CODE \
	|| img->color == RED_CODE)
		set_color_rgb(x, y, i, img);
	if (img->color == PALLETE_CODE)
	{
		set_color_pallete(x, y, i, img);
	}
	if (img->color == BERNSTEIN_CODE)
	{
		set_color_bernstein(x, y, i, img);
	}
}
