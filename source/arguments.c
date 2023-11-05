/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:41:45 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 22:19:42 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	args_help(void)
{
	ft_putstr_fd("\n== TIPS TO THABECK'S FRACTOL ==\n", 1);
	ft_putstr_fd("----------------------------------\n", 1);
	ft_putstr_fd("Arguments Guide:\n\n", 1);
	ft_putstr_fd("./fractol mandelbrot\n", 1);
	ft_putstr_fd("./fractol julia X.XXX X.XXX\n", 1);
	ft_putstr_fd("./fractol starjulia X.XXX X.XXX\n", 1);
	ft_putstr_fd("Thus X.XXX are any double number.\n", 1);
	ft_putstr_fd("----------------------------------\n", 1);
	ft_putstr_fd("Julia | Starjulia tips: \n\n", 1);
	ft_putstr_fd("(-0.391, -0.587)\t(-0.4, -0.6)\t\t(-0.835, -0.2321)\n", 1);
	ft_putstr_fd("(0.285, 0.0)\t\t(0.285, 0.01)\t\t(-0.74, 0.12)\n", 1);
	ft_putstr_fd("(-1.312, 0.0)\t\t(0.37, -0.28)\t\t(0.45, 0.1428)\n", 1);
	ft_putstr_fd("(-0.70176, -0.3842)\t(-0.70469, -0.5239)\t", 1);
	ft_putstr_fd("(-0.5239, 0.69969)\n", 1);
	ft_putstr_fd("----------------------------------\n", 1);
}

int	check_julia(char *nbr)
{
	int	index;

	index = 0;
	if (nbr[index] == '+' || nbr[index] == '-')
		index++;
	if (!ft_isdigit(nbr[index]))
		return (0);
	index++;
	if (!(nbr[index] == '.'))
		return (0);
	index++;
	if (!ft_isdigit(nbr[index]))
		return (0);
	while (ft_isdigit(nbr[index]))
		index++;
	if (nbr[index])
		return (0);
	return (1);
}

int	arg_verify(int argc, char **argv, t_win	*win)
{
	if (argc == 2 && !ft_strncmp(MANDELBROT_ARG, argv[1], 10))
	{
		win->img.type = MANDELBROT_CODE;
		return (1);
	}
	else if (argc == 4 && !ft_strncmp(JULIA_ARG, argv[1], 5) \
	&& check_julia(argv[2]) && check_julia(argv[3]))
	{
		win->img.type = JULIA_CODE;
		return (1);
	}
	else if (argc == 4 && !ft_strncmp(STARJULIA_ARG, argv[1], 9) \
	&& check_julia(argv[2]) && check_julia(argv[3]))
	{
		win->img.type = STARJULIA_CODE;
		return (1);
	}
	return (0);
}
