#include "fractol.h"

double	convert_range(double new_min, double new_max, double value)
{
	return ((((value - 0) * (new_max - new_min)) / (WIDTH - 0)) + new_min);
}

// int get_color(int iterations)
// {
//     return (iterations * 255 / 100) << 16;
// }
int get_color(int iterations)
{
    double t = (double)iterations / ITERATION;
    
    int red = (int)(9 * (1 - t) * t * t * t * 255);
    int green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    
    return red * 65536 + green * 256 + blue;
}



void colour_pixel(int x, int y, t_data *fractol, int n)
{
    if (n == 1)
        colour_mandelbrot(x, y, fractol);
    else if (n == 2)
		colour_julia(x, y, fractol);
	// else if (n == 3)
	// 	; // bonus
}

void fractal(t_data *fractol, int n)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(x < WIDTH)
    {
        y = 0;
        while(y < HEIGHT)
        {
            colour_pixel(x, y, fractol, n);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractol->mlx_ptr, fractol->mlx_window, fractol->img.img, 0, 0);
}
