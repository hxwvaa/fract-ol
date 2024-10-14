#include "fractol.h"

double	convert_range(double new_min, double new_max, double value)
{
	return ((((value - 0) * (new_max - new_min)) / (WIDTH - 0)) + new_min);
}

int	get_color(int iterations, int theme)
{
	double	t;

	t = (double)iterations / ITERATION;
	if (theme == 1)
		return ((((int)(255 * (t * 3)) % 256) * 65536) + (((int)(255 * (t * 5))
					% 256) * 256) + (int)(255 * (t * 7)) % 256);
	else if (theme == 2)
		return ((((int)(255 * (t * 5)) % 256) * 65536) + (((int)(255 * (t * 3))
					% 256) * 256) + (int)(255 * (t * 7)) % 256);
	else if (theme == 3)
		return ((((int)(255 * (t * 14)) % 256) * 65536) + (((int)(255 * (t
							* 12)) % 256) * 256) + (int)(255 * (t * 16)) % 256);
	else if (theme == 4)
		return ((((int)(255 * (t * 1)) % 256) * 65536) + (((int)(255 * (t * 2))
					% 256) * 256) + (int)(255 * (t * 3)) % 256);
	else
		return ((((int)(255 * t)) * 65536) + (((int)(255 * t)) * 256)
			+ ((int)(255 * t)));
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
