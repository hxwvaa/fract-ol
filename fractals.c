#include "fractol.h"

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
    while ((z.x * z.x) + (z.y * z.y) <= 4 && iterations < fractol->iterations)
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

