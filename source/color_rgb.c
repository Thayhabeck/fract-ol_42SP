/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:22:32 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 14:43:42 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	set_color_blue(int iteration, t_img *img)
{
	int	color;

	color = BLACK;
	if (iteration >= img->max_iter)
		color = BLACK;
	else if ((iteration / img->range) % 5 == 1)
		color = BLUE1;
	else if ((iteration / img->range) % 5 == 2)
		color = BLUE2;
	else if ((iteration / img->range) % 5 == 3)
		color = BLUE3;
	else if ((iteration / img->range) % 5 == 4)
		color = BLUE4;
	else if ((iteration / img->range) % 5 == 0)
		color = BLUE5;
	return (color);
}

int	set_color_red(int iteration, t_img *img)
{
	int	color;

	color = BLACK;
	if (iteration >= img->max_iter)
		color = BLACK;
	else if ((iteration / img->range) % 5 == 1)
		color = RED1;
	else if ((iteration / img->range) % 5 == 2)
		color = RED2;
	else if ((iteration / img->range) % 5 == 3)
		color = RED3;
	else if ((iteration / img->range) % 5 == 4)
		color = RED4;
	else if ((iteration / img->range) % 5 == 0)
		color = RED5;
	return (color);
}

int	set_color_green(int iteration, t_img *img)
{
	int	color;

	color = BLACK;
	if (iteration >= img->max_iter)
		color = BLACK;
	else if ((iteration / img->range) % 5 == 1)
		color = GREEN1;
	else if ((iteration / img->range) % 5 == 2)
		color = GREEN2;
	else if ((iteration / img->range) % 5 == 3)
		color = GREEN3;
	else if ((iteration / img->range) % 5 == 4)
		color = GREEN4;
	else if ((iteration / img->range) % 5 == 0)
		color = GREEN5;
	return (color);
}

void	set_color_rgb(double x, double y, int iteration, t_img *img)
{
	int	color;

	if (img->color == BLUE_CODE)
		color = set_color_blue(iteration, img);
	else if (img->color == RED_CODE)
		color = set_color_red(iteration, img);
	else
		color = set_color_green(iteration, img);
	my_mlx_pixel_put(img, x / img->pass - img->xmin / img->pass, \
	y / img->pass - img->ymin / img->pass, color);
}
