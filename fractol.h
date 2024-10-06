#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_opengl/mlx.h"
// # include <OpenGL/gl.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>


#define WIDTH 800
#define HEIGHT 800

#define ITERATION 200

#define ESC_KEY 91

#define ESC_KEY_L 65307

typedef struct s_value
{
	double x;
	double y;
}	t_value;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_window;
    char *fractal_name;
	int iterations;
	t_img img;
	double shift_x;
	double shift_y;
	double zoom;
}			t_data;

size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int i);

void		format_error(void);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void fractal(t_data *fractol, int n);
void colour_mandelbrot(int x, int y, t_data *fractol);

double	convert_range(double new_min, double new_max, double value);

int handle_keys(int key, t_data *fractol);
#endif