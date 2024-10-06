#include "fractol.h"

void close_fractol(t_data *fractol)
{
    mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_window);
    free(fractol->mlx_ptr);
    exit(0);
}

int handle_keys(int key, t_data *fractol)
{
    if (key == ESC_KEY_L)
        close_fractol(fractol);
    return(1);
}