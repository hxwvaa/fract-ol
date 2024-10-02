#include "fractol.h"

// void colour_mandelbrot (int x, int y, t_data *fractol)
// {
//     t_value z;
//     t_value c;

//     z.x = convert_range(-2, 2, x);
//     z.y = convert_range(-2, 2, y);
    
// }

double	convert_range(double new_min, double new_max, double value)
{
	return ((((value - 0) * (new_max - new_min)) / (WIDTH - 0)) + new_min);
}

int get_color(int iterations)
{
    return (iterations * 255 / 100) << 16; // Simple red gradient based on iterations
}


void colour_mandelbrot(int x, int y, t_data *fractol)
{
    t_value z;
    t_value c;
    int iterations;
    double temp_x;

    c.x = convert_range(-2, 2, x); 
    c.y = convert_range(-2, 2, y);

    z.x = 0;
    z.y = 0;
    iterations = 0;
    fractol->iterations = 1000;

    while ((z.x * z.x) + (z.y * z.y) <= 2 && iterations < fractol->iterations)
    {
        temp_x = z.x * z.x - z.y * z.y + c.x;
        z.y = 2 * z.x * z.y + c.y;
        z.x = temp_x;
        iterations++;
    }

    if (iterations == fractol->iterations)
        my_mlx_pixel_put(fractol, x, y, 0x000000);
    else
        my_mlx_pixel_put(fractol, x, y, get_color(iterations));
}

void mandelbrot(t_data *fractol)
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
            colour_mandelbrot(x, y, fractol);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractol->mlx_ptr, fractol->mlx_window, fractol->img.img, 0, 0);
}
