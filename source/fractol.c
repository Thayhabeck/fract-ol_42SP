/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:40:30 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 22:02:22 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_image(t_img *img)
{
	double	x;
	double	y;
	int		i;

	img->pass = (img->xmax - img->xmin) / WIN_SIDE;
	x = img->xmin;
	while (x <= img->xmax)
	{
		y = img->ymin;
		while (y <= img->ymax)
		{
			if (img->type == MANDELBROT_CODE)
				i = mandelbrot(x, y, img);
			else if (img->type == JULIA_CODE)
				i = julia(x, y, img);
			else if (img->type == STARJULIA_CODE)
				i = starjulia(x, y, img);
			set_color(x, y, i, img);
			y += img->pass;
		}
		x += img->pass;
	}
}

void	set_image(t_win *win)
{
	win->img.img = mlx_new_image(win->mlx, WIN_SIDE, WIN_SIDE);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bpp, \
	&win->img.line_len, &win->img.endian);
	print_image(&(win->img));
	mlx_put_image_to_window(win->mlx, win->win_ptr, win->img.img, 0, 0);
	mlx_destroy_image(win->mlx, win->img.img);
}

int	set_window(t_win *win)
{
	win->mlx = mlx_init();
	if (win->mlx == NULL)
		return (MLX_ERROR);
	win->win_ptr = mlx_new_window(win->mlx, WIN_SIDE, WIN_SIDE, WIN_TITLE);
	if (win->win_ptr == NULL)
	{
		free(win->win_ptr);
		return (MLX_ERROR);
	}
	set_image(win);
	control_log();
	mlx_mouse_hook(win->win_ptr, zoom, win);
	mlx_hook(win->win_ptr, 17, 1L << 0, &close_window, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, &handle_input, win);
	mlx_expose_hook(win->win_ptr, (void *)set_image, win);
	mlx_loop(win->mlx);
	return (0);
}

double	convert_params(char *nbr)
{
	double	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*nbr == '+' || *nbr == '-')
	{
		sign = -1;
		nbr++;
	}
	result = *nbr - 48;
	nbr += 2;
	result += (double)(ft_atoi(nbr)) / (double)(pow(10, ft_strlen(nbr)));
	return (result * sign);
}

void	set_params(char **argv, t_win *win)
{
	win->img.color = BERNSTEIN_CODE;
	win->img.xmin = -2.0;
	win->img.xmax = 2.0;
	win->img.ymin = -2.0;
	win->img.ymax = 2.0;
	win->img.range = 9;
	win->img.max_iter = MAX_ITER;
	if (win->img.type == JULIA_CODE || win->img.type == STARJULIA_CODE)
	{
		win->img.julia_x = convert_params(argv[2]);
		win->img.julia_y = convert_params(argv[3]);
	}
}
