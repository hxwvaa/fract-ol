#include "fractol.h"
#include <stdio.h>

int	chk_val(char *val)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (val[i])
	{
		if (ft_isdigit(val[i]) || val[i] == '.')
			;
		else
			return (0);
		if (val[i] == '.')
		{
			if (flag == 1)
				return (0);
			flag = 1;
		}
		i++;
	}
	return (1);
}

int	check_arg(int ac, char **av, t_data *fractol)
{
	if (ac == 2 && ft_strncmp("mandelbrot", av[1], ft_strlen("mandelbrot")
			+ 1) == 0)
	{
		fractol->fractal_name = "Mandelbrot";
		fractol->fract_n = 1;
		return (1);
	}
	else if (ac == 4 && ft_strncmp("julia", av[1], ft_strlen("julia") + 1) == 0
		&& (chk_val(av[2]) && chk_val(av[3])))
	{
		fractol->fractal_name = "Julia";
		fractol->fract_n = 2;
		return (2);
	}
	// add for bonus
	return (-1);
}

void	initialize_struct(t_data *fractol)
{
	fractol->mlx_ptr = mlx_init();
	fractol->mlx_window = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT,
			fractol->fractal_name);
	fractol->iterations = ITERATION;
	fractol->img.img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	fractol->zoom = 1;
	fractol->shift_x = 0;
	fractol->shift_y = 0;
    
}

int render_again(t_data *fractol)
{
	fractal(fractol, fractol->fract_n);
    mlx_put_image_to_window(fractol->mlx_ptr, fractol->mlx_window, fractol->img.img, 0, 0);
	return(1);
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
	initialize_struct(&fractol);
	fractal(&fractol, n);
	mlx_key_hook(fractol.mlx_window, handle_keys, &fractol);
	// mlx_mouse_hook(fractol.mlx_window, handle_mouse, &fractol);
	// mlx_loop_hook(fractol.mlx_ptr, render_again, &fractol);
	mlx_hook(fractol.mlx_window, 17, 0, close_fractol, &fractol);

	mlx_loop(fractol.mlx_ptr);
}
