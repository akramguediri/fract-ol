/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:56:48 by aguediri          #+#    #+#             */
/*   Updated: 2023/08/06 09:22:57 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelate(t_mandel *m, int x, int y)
{
	m->re = m->xmin + (double)x / m->image->width * (m->xmax - m->xmin);
	m->im = m->ymin + (double)y / m->image->height * (m->ymax - m->ymin);
	m->cre = m->re;
	m->cim = m->im;
	m->iterations = 0;
	m->zre = 0.0;
	m->zim = 0.0;
}

void	updatevalues(t_mandel *m)
{
	double	zretemp;

	zretemp = m->zre * m->zre - m->zim * m->zim + m->cre;
	m->zim = 2.0 * m->zre * m->zim + m->cim;
	m->zre = zretemp;
	m->iterations++;
}

void	ft_mandelbrot(void *param)
{
	uint32_t	y;
	uint32_t	x;
	t_mandel	*m;

	m = (t_mandel *)param;
	if (m->should_draw != 1)
		return ;
	y = 0;
	while (++y < m->image->height)
	{
		x = 0;
		while (++x < m->image->width)
		{
			mandelate(m, x, y);
			while (m->iterations < MAXITERATIONS && m->zre * m->zre + m->zim
				* m->zim <= 4.0)
			{
				updatevalues(m);
			}
			m->color = ft_pixel(m->iterations % 128, m->iterations % 64,
					m->iterations % 255, 255);
			mlx_put_pixel(m->image, x, y, m->color);
		}
	}
	m->should_draw = 0;
}
