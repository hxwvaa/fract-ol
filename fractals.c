#include "fractol.h"

double	convert_range(double new_min, double new_max, double value)
{
	return ((((value - 0) * (new_max - new_min)) / (WIDTH - 0)) + new_min);
}

int	get_color(int iterations, int theme)
{
	double	t;

	t = (double)iterations / ITERATION;
	if (theme == 1) // blue Theme
		return ((((int)(255 * (t * 3)) % 256) * 65536) + (((int)(255 * (t * 5))
					% 256) * 256) + (int)(255 * (t * 7)) % 256);
	else if (theme == 2) // purple Theme
		return ((((int)(255 * (t * 5)) % 256) * 65536) + (((int)(255 * (t
							* 3)) % 256) * 256) + (int)(255 * (t * 7)) % 256);
	else if (theme == 3) // cool greenish white  Theme
		return ((((int)(255 * (t * -14)) % 256) * 65536) + (((int)(255 * (t
							* -12)) % 256) * 256) + (int)(255 * (t * -16)) % 256);
	else if (theme == 4) // weird white theme
		return ((((int)(255 * (t * -1)) % 256) * 65536) + (((int)(255 * (t
							* -2)) % 256) * 256) + (int)(255 * (t * -3)) % 256);
	else // Default Black and White Theme
	    return (((int)(255 * t) * 65536) + ((int)(255 * t) * 256) + (int)(255 * t));
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
