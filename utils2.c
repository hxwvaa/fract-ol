#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void zoom_fractal(t_data *fractol, int mouse_x, int mouse_y, int key)
{
	double x;
	double y;
	double screen_x;
	double screen_y;

	x = 0;
	y = 0;
	screen_x = 0;
	screen_y = 0;
	x = (convert_range(-2, 2, mouse_x) * fractol->zoom) + fractol->shift_x; 
    y = (convert_range(2, -2, mouse_y) * fractol->zoom) + fractol->shift_y;

	if (key == MOUSE_LMB)
		fractol->zoom /=1.2;
	else if (key == MOUSE_RMB)
		fractol->zoom *= 1.2;
	screen_x = (convert_range(-2, 2, mouse_x) * fractol->zoom) + fractol->shift_x; 
    screen_y = (convert_range(2, -2, mouse_y) * fractol->zoom) + fractol->shift_y;
	fractol->shift_x += (x - screen_x);
	fractol->shift_y += (y - screen_y);
}