#include "fractol.h"

int close_fractol(t_data *fractol)
{
    mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_window);
    free(fractol->mlx_ptr);
    exit(0);
    return(0);
}

int handle_keys(int key, t_data *fractol)
{
    if (key == ESC_KEY_L)
        close_fractol(fractol);
    else if (key == KEY_RIGHT_L)
        fractol->shift_x -= 0.1 * fractol->zoom;
    else if (key == KEY_LEFT_L)
        fractol->shift_x += 0.1 * fractol->zoom;
    else if (key == KEY_UP_L)
        fractol->shift_y += 0.1 * fractol->zoom;
    else if (key == KEY_DOWN_L)
        fractol->shift_y -= 0.1 * fractol->zoom;
    else if (key == KEY_EQUAL_L)
        fractol->iterations += 10;
    else if (key == KEY_MINUS_L)
        fractol->iterations -= 10;    
    fractal(fractol, fractol->fract_n);
    return(1);
}

int handle_mouse(int key, int mouse_x, int mouse_y, t_data *fractol)
{
    mlx_mouse_get_pos(fractol->mlx_window, &mouse_x, &mouse_y);
    if (key == MOUSE_LMB)
        zoom_fractal(fractol, mouse_x, mouse_y, MOUSE_LMB);
    else if (key == MOUSE_RMB)
        zoom_fractal(fractol, mouse_x, mouse_y, MOUSE_RMB);
    else if (key == MOUSE_SCROLL_UP)
        fractol->zoom *= 1.2;
    else if (key == MOUSE_SCROLL_DOWN)
        fractol->zoom /= 1.2;
    fractal(fractol, fractol->fract_n);
    return(1);
}
