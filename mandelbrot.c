#include "fractol.h"

void mandelbrot(t_data *fractol)
{

            my_mlx_pixel_put(fractol, i, j, 0x00FF0000);

    mlx_put_image_to_window(fractol->mlx_ptr, fractol->mlx_window, fractol->img.img, 0, 0);
}