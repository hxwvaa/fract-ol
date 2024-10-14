/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:11:19 by hbasheer          #+#    #+#             */
/*   Updated: 2024/10/14 13:47:33 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	convert_range(double new_min, double new_max, double value)
{
	return ((((value - 0) * (new_max - new_min)) / (WIDTH - 0)) + new_min);
}

int	get_color(int iterations, int theme)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iterations / ITERATION;
	if (theme == 1)
	{
		r = (int)(128.0 * (1 + sin(M_PI * 2 * t * 3)));
		g = (int)(128.0 * (1 + sin(M_PI * 2 * t * 5)));
		b = (int)(128.0 * (1 + sin(M_PI * 2 * t * 7)));
	}
	else if (theme == 2)
	{
		r = (int)(128.0 * (1 + sin(M_PI * 2 * t * 4)));
		g = (int)(128.0 * (1 + sin(M_PI * 2 * t * 2)));
		b = (int)(128.0 * (1 + sin(M_PI * 2 * t * 6)));
	}
	else
	{
		r = (int)(128.0 * (1 + sin(M_PI * 2 * t * 15)));
		g = (int)(128.0 * (1 + sin(M_PI * 2 * t * 13)));
		b = (int)(128.0 * (1 + sin(M_PI * 2 * t * 17)));
	}
	return ((r << 16) | (g << 8) | b);
}

void	colour_pixel(int x, int y, t_data *fractol, int n)
{
	if (n == 1)
		colour_mandelbrot(x, y, fractol);
	else if (n == 2)
		colour_julia(x, y, fractol);
	else if (n == 3)
		colour_burning_ship(x, y, fractol);
}

void	fractal(t_data *fractol, int n)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			colour_pixel(x, y, fractol, n);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->mlx_window,
		fractol->img.img, 0, 0);
}

int	check_arg(int ac, char **av, t_data *fractol)
{
	if (ac == 2 && ft_strncmp("mandelbrot", av[1], ft_strlen("mandelbrot")
			+ 1) == 0)
	{
		fractol->fractal_name = "Mandelbrot";
		fractol->fract_n = 1;
		return (1);
	}
	else if (ac == 4 && ft_strncmp("julia", av[1], ft_strlen("julia") + 1) == 0
		&& (chk_val(av[2]) && chk_val(av[3])))
	{
		fractol->fractal_name = "Julia";
		fractol->fract_n = 2;
		return (2);
	}
	else if (ac == 2 && ft_strncmp("burning_ship", av[1],
			ft_strlen("burning_ship") + 1) == 0)
	{
		fractol->fractal_name = "Burning_ship";
		fractol->fract_n = 3;
		return (3);
	}
	return (-1);
}
