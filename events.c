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
    if (key == ESC_KEY_L || key == ESC_KEY_M)
        close_fractol(fractol);
    else if (key == KEY_SPACE_BAR_L || key == KEY_SPACE_BAR_M)
        reset(fractol);
    else if (key == KEY_RIGHT_L || key == KEY_RIGHT_M)
        fractol->shift_x += 0.1 * fractol->zoom;
    else if (key == KEY_LEFT_L || key == KEY_LEFT_M)
        fractol->shift_x -= 0.1 * fractol->zoom;
    else if (key == KEY_UP_L || key == KEY_UP_M)
        fractol->shift_y += 0.1 * fractol->zoom;
    else if (key == KEY_DOWN_L || key == KEY_DOWN_M)
        fractol->shift_y -= 0.1 * fractol->zoom;
    else if (key == KEY_EQUAL_L || key == KEY_EQUAL_M)
        fractol->iterations += 10;
    else if (key == KEY_MINUS_L || key == KEY_MINUS_M)
        fractol->iterations -= 10;
    else if (key == KEY_M_L || key == KEY_M_M)
        fractol->move_mouse *= -1;
    else if (key == KEY_C_L || key == KEY_C_M)
        fractol->theme += 1;
    if (fractol->theme > 5)
        fractol->theme = 1;
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

int move_mouse(int mouse_x, int mouse_y, t_data *fractol)
{
    double x;
    double y;

    x = (convert_range(-2, 2, mouse_x) * fractol->zoom) + fractol->shift_x; 
    y = (convert_range(2, -2, mouse_y) * fractol->zoom) + fractol->shift_y;
    if (fractol->fract_n == 2 && fractol->move_mouse == 1)
    {
        fractol->julia_x = x;
        fractol->julia_y = y;
    }
    return(1);
}