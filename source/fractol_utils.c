/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:41:42 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 17:46:12 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win_ptr);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
	return (0);
}

void	change_pallete(int keysys, t_win *win)
{
	if (keysys == R_KEY)
		win->img.color = RED_CODE;
	else if (keysys == G_KEY)
		win->img.color = GREEN_CODE;
	else if (keysys == B_KEY)
		win->img.color = BLUE_CODE;
	else if (keysys == C_KEY)
	{
		if (win->img.color == BERNSTEIN_CODE)
			win->img.color = PALLETE_CODE;
		else
			win->img.color = BERNSTEIN_CODE;
	}
	color_log(win->img.color);
}

void	change_range(int keysys, t_win *win)
{
	if (keysys == A_KEY)
		if (win->img.range < 9)
			win->img.range += 1;
	if (keysys == D_KEY)
		if (win->img.range > 1)
			win->img.range -= 1;
	if (keysys == W_KEY)
		win->img.max_iter += 50;
	if (keysys == S_KEY)
		if (win->img.max_iter > 50)
			win->img.max_iter -= 50;
	interation_log(win->img.max_iter, win->img.range);
}
