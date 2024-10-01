#include "fractol.h"

void colour_mandelbrot (int x, int y, t_data *fractol)
{
    t_value z;
    t_value c;

    z.x = convert_range(-2, 2, x);
    z.y = convert_range(-2, 2, y);
    
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
}