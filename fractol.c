/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:34:17 by aguediri          #+#    #+#             */
/*   Updated: 2023/08/06 09:35:13 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(double xdelta, double ydelta, void *param)
{
	t_mandel	*m;
	mlx_t		*mlx;
	double		z;

	m = (t_mandel *)param;
	mlx = (mlx_t *)param;
	z = 0.1;
	xdelta = 0;
	if (ydelta > 0)
	{
		m->xmin += (m->xmax - m->xmin) * z;
		m->xmax -= (m->xmax - m->xmin) * z;
		m->ymin += (m->ymax - m->ymin) * z;
		m->ymax -= (m->ymax - m->ymin) * z;
	}
	else if (ydelta < 0)
	{
		m->xmin -= (m->xmax - m->xmin) * z;
		m->xmax += (m->xmax - m->xmin) * z;
		m->ymin -= (m->ymax - m->ymin) * z;
		m->ymax += (m->ymax - m->ymin) * z;
	}
	m->should_draw = 1;
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_mandel	*m;

	m = (t_mandel *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		up(m);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		m->ymin -= (m->ymax - m->ymin) * -0.1;
		m->ymax -= (m->ymax - m->ymin) * -0.1;
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		m->xmin += (m->xmax - m->xmin) * -0.1;
		m->xmax += (m->xmax - m->xmin) * -0.1;
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		m->xmin -= (m->xmax - m->xmin) * -0.1;
		m->xmax -= (m->xmax - m->xmin) * -0.1;
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (exit (0));
	m->should_draw = 1;
}

int	ft_cleaninit(mlx_t *mlx, t_mandel *m)
{
	if (!(mlx))
	{
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	m->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!(m->image))
	{
		mlx_close_window(mlx);
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, m->image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	return (1);
}

void	ft_init(t_mandel *m, char **c, mlx_t *mlx, int argc)
{
	m->should_draw = 1;
	if (c[1][0] == 'm' && argc == 2)
	{
		m->xmin = -2.5;
		m->xmax = 1.0;
		m->ymin = -1.5;
		m->ymax = 1.5;
		mlx_loop_hook(mlx, ft_mandelbrot, m);
	}
	else if (c[1][0] == 'j' && argc == 4)
	{
		m->xmin = -1.5;
		m->xmax = 1.5;
		m->ymin = -1.5;
		m->ymax = 1.5;
		m->cre = ft_atof(c[2]);
		m->cim = ft_atof(c[3]);
		mlx_loop_hook(mlx, ft_julia, m);
	}
	else
	{
		write(1, "\nyou did not set params to julia or did to mandelbrot\n", 55);
		exit(0);
	}
}

int32_t	main(int32_t argc, char *argv[])
{
	mlx_t		*mlx;
	t_mandel	*m;

	if (argc > 1)
	{
		mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
		m = (t_mandel *)malloc(sizeof(t_mandel));
		if (ft_cleaninit(mlx, m) && m)
		{
			mlx_scroll_hook(mlx, zoom, m);
			ft_init(m, argv, mlx, argc);
			mlx_key_hook(mlx, ft_hook, m);
			mlx_loop(mlx);
			mlx_terminate(mlx);
			return (EXIT_SUCCESS);
		}
		free(m);
	}
	else
	{
		write(1, "\nchoose j for julia and m for mandelbrot\n", 41);
		return (EXIT_FAILURE);
	}
}
