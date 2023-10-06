/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:37:59 by aguediri          #+#    #+#             */
/*   Updated: 2023/08/06 09:29:43 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1080
# define HEIGHT 1080
# define MAXITERATIONS 1000

typedef struct MandelbrotParams
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		re;
	double		im;
	double		cre;
	double		cim;
	int			iterations;
	double		zre;
	double		zim;
	double		zretemp;
	uint32_t	color;
	mlx_image_t	*image;
	mlx_t		*mlx;
	int			should_draw;
}				t_mandel;

void			ft_mandelbrot(void *param);
int				juliafun(float fr, float fi, float cr, float ci);
void			ft_julia(void *param);
int32_t			ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
double			ft_atof(const char *str);
void			up(t_mandel *m);
#endif