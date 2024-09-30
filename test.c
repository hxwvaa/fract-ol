#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    int i = 0;
    int j = 0;

	int x = 0;
	int y = 0;

	int x_c;
	int y_c;

	int iter = 0;
	int max_iter = 400;

	int x_temp = 0;
    while(j++ < 400)
    {
        i = 0;
        while(i++ < 400)
		{
			while( x*x + y*y <= 500000 && iter < max_iter)
			{
				x_c = x;
				y_c = y;
				x_temp = x*x - y*y + x_c;
				y = 2*x*y + y_c;
				x = x_temp;
				iter++;
				x++;
				y++;
				write(1, "1", 1);
			}
			if (iter == max_iter)
				mlx_pixel_put(mlx, mlx_win, x_c, y_c, 0x00FF0000);
			else
				mlx_pixel_put(mlx, mlx_win, x_c, y_c, 0xFFFFFFFF);
		}
        
    }
	// while( x*x + y*y <= (2*2) && iter < max_iter)
	// {
	// 	x_c = x;
	// 	y_c = y;
	// 	x_temp = x*x - y*y + x_c;
	// 	y = 2*x*y + y_c;
	// 	x = x_temp;
	// 	iter++;
	// }
    // // mlx_pixel_put(mlx, mlx_win, i, j, 0x00FF0000);
	// if (iter == max_iter)
	// 	mlx_pixel_put(mlx, mlx_win, x_c, y_c, iter);
	// else
	// 	mlx_pixel_put(mlx, mlx_win, x_c, y_c, 0xFFFFFFFF);
	// // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

