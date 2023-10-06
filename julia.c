/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 04:51:52 by aguediri          #+#    #+#             */
/*   Updated: 2023/08/05 00:04:18 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	juliafun(float fr, float fi, float cr, float ci)
{
	int		iterations;
	double	temp;

	iterations = 0;
	while (iterations < MAXITERATIONS && (fr * fr + fi * fi) <= 4)
	{
		temp = fr * fr - fi * fi + cr;
		fi = 2 * fr * fi + ci;
		fr = temp;
		iterations++;
	}
	return (iterations);
}

void	ft_julia(void *param)
{
	t_mandel	*m;
	uint32_t	x;
	uint32_t	y;

	m = (t_mandel *)param;
	if (m->should_draw != 1)
		return ;
	y = 0;
	while (++y < m->image->height)
	{
		x = 0;
		while (++x < m->image->width)
		{
			m->re = m->xmin + (double)x / m->image->width * (m->xmax - m->xmin);
			m->im = m->ymin + (double)y / m->image->height * (m->ymax
					- m->ymin);
			m->iterations = juliafun(m->re, m->im, m->cre, m->cim);
			m->color = ft_pixel(m->iterations % 256, m->iterations % 128,
					m->iterations % 64, 255);
			mlx_put_pixel(m->image, x, y, m->color);
		}
	}
	m->should_draw = 0;
}
