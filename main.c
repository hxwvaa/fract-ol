/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:11:11 by hbasheer          #+#    #+#             */
/*   Updated: 2024/10/14 13:11:12 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_struct(t_data *fractol, char **av)
{
	fractol->mlx_ptr = mlx_init();
	if (!fractol->mlx_ptr)
		exit(EXIT_FAILURE);
	fractol->mlx_window = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT,
			fractol->fractal_name);
	if (!fractol->mlx_window)
		(free(fractol->mlx_ptr), exit(EXIT_FAILURE));
	fractol->iterations = ITERATION;
	fractol->img.img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (!fractol->img.img)
		(mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_window),
			free(fractol->mlx_ptr), exit(EXIT_FAILURE));
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	if (fractol->fract_n == 2)
	{
		fractol->julia_x = ft_atof(av[2]);
		fractol->julia_y = ft_atof(av[3]);
	}
	fractol->move_mouse = -1;
	fractol->zoom = 1;
	fractol->shift_x = 0;
	fractol->shift_y = 0;
	fractol->theme = 1;
}

int	main(int ac, char **av)
{
	t_data	fractol;
	int		n;

	if (ac == 1)
		format_error();
	n = check_arg(ac, av, &fractol);
	if (n == -1)
		format_error();
	initialize_struct(&fractol, av);
	fractal(&fractol, n);
	mlx_hook(fractol.mlx_window, 2, 0, handle_keys, &fractol);
	mlx_mouse_hook(fractol.mlx_window, handle_mouse, &fractol);
	mlx_hook(fractol.mlx_window, 17, 0, close_fractol, &fractol);
	mlx_hook(fractol.mlx_window, 6, 6, move_mouse, &fractol);
	mlx_loop(fractol.mlx_ptr);
}
