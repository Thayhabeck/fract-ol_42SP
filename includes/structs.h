/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:34:46 by thabeck-          #+#    #+#             */
/*   Updated: 2022/08/16 17:54:29 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/******************************************************************************\
 * IMAGE
\******************************************************************************/

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		type;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	pass;
	int		color;
	int		range;
	double	julia_x;
	double	julia_y;
	double	max_iter;
}				t_img;

/******************************************************************************\
 * WINDOW
\******************************************************************************/

typedef struct s_win {
	void	*mlx;
	char	*win_ptr;
	t_img	img;
}				t_win;

#endif
