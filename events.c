/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:11:05 by hbasheer          #+#    #+#             */
/*   Updated: 2024/10/14 13:11:06 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_fractol(t_data *fractol)
{
	mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_window);
	free(fractol->mlx_ptr);
	exit(0);
	return (0);
}

int	handle_keys(int key, t_data *fractol)
{
	if (key == ESC_KEY)
		close_fractol(fractol);
	else if (key == KEY_SPACE_BAR)
		reset(fractol);
	else if (key == KEY_RIGHT)
		fractol->shift_x += 0.1 * fractol->zoom;
	else if (key == KEY_LEFT)
		fractol->shift_x -= 0.1 * fractol->zoom;
	else if (key == KEY_UP)
		fractol->shift_y -= 0.1 * fractol->zoom;
	else if (key == KEY_DOWN)
		fractol->shift_y += 0.1 * fractol->zoom;
	else if (key == KEY_EQUAL)
		fractol->iterations += 10;
	else if (key == KEY_MINUS)
		fractol->iterations -= 10;
	else if (key == KEY_M)
		fractol->move_mouse *= -1;
	else if (key == KEY_C)
		fractol->theme += 1;
	if (fractol->theme > 3)
		fractol->theme = 1;
	fractal(fractol, fractol->fract_n);
	return (1);
}

int	handle_mouse(int key, int mouse_x, int mouse_y, t_data *fractol)
{
	mlx_mouse_get_pos(fractol->mlx_window, &mouse_x, &mouse_y);
	if (key == MOUSE_LMB)
		zoom_fractal(fractol, mouse_x, mouse_y, MOUSE_LMB);
	else if (key == MOUSE_RMB)
		zoom_fractal(fractol, mouse_x, mouse_y, MOUSE_RMB);
	else if (key == MOUSE_SCROLL_UP)
		zoom_fractal(fractol, mouse_x, mouse_y, MOUSE_LMB);
	else if (key == MOUSE_SCROLL_DOWN)
		zoom_fractal(fractol, mouse_x, mouse_y, MOUSE_RMB);
	fractal(fractol, fractol->fract_n);
	return (1);
}

int	move_mouse(int mouse_x, int mouse_y, t_data *fractol)
{
	double	x;
	double	y;

	x = (convert_range(-2, 2, mouse_x) * fractol->zoom) + fractol->shift_x;
	y = (convert_range(-2, 2, mouse_y) * fractol->zoom) + fractol->shift_y;
	if (fractol->fract_n == 2 && fractol->move_mouse == 1)
	{
		fractol->julia_x = x;
		fractol->julia_y = y;
	}
	fractal(fractol, fractol->fract_n);
	return (1);
}
