/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:11:03 by hbasheer          #+#    #+#             */
/*   Updated: 2024/10/14 13:11:04 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colour_burning_ship(int x, int y, t_data *fractol)
{
	t_value	z;
	t_value	c;
	int		iterations;
	double	temp_x;

	z.x = (convert_range(-2, 2, x) * fractol->zoom) + fractol->shift_x;
	z.y = (convert_range(-2, 2, y) * fractol->zoom) + fractol->shift_y;
	c.x = z.x;
	c.y = z.y;
	iterations = 0;
	while (hypot(z.x, z.y) <= 2 && iterations < fractol->iterations)
	{
		temp_x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * fabs(z.x) * fabs(z.y) + c.y;
		z.x = fabs(temp_x);
		iterations++;
	}
	if (iterations == fractol->iterations)
		my_mlx_pixel_put(fractol, x, y, 0x000000);
	else
		my_mlx_pixel_put(fractol, x, y, get_color(iterations, fractol->theme));
}
