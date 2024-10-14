#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 200
# define HEIGHT 200

# define ITERATION 200

# ifdef __APPLE__
#  include "minilibx_opengl/mlx.h"
#  include <OpenGL/gl.h>
// Keys Mac
#  define ESC_KEY 53       // Escape key
#  define KEY_LEFT 123     // Left arrow key
#  define KEY_RIGHT 124    // Right arrow key
#  define KEY_UP 126       // Up arrow key
#  define KEY_DOWN 125     // Down arrow key
#  define KEY_EQUAL 24     // Equals key (=)
#  define KEY_MINUS 27     // Minus key (-)
#  define KEY_SPACE_BAR 49 // Space bar
#  define KEY_M 46         // 'M' key
#  define KEY_C 8          // 'C' key
# else
#  include "minilibx-linux/mlx.h"
// Keys Linux
#  define ESC_KEY 65307
#  define KEY_LEFT 65361   // Left arrow key
#  define KEY_RIGHT 65363  // Right arrow key
#  define KEY_UP 65362     // Up arrow key
#  define KEY_DOWN 65364   // Down arrow key
#  define KEY_EQUAL 61     // Equals key (=)
#  define KEY_MINUS 45     // Minus key (-)
#  define KEY_SPACE_BAR 32 // Space bar
#  define KEY_M 109        // 'M' key
#  define KEY_C 99         // 'C' key
# endif

// Mouse Click/Scroll
# define MOUSE_LMB 1         // Left mouse button
# define MOUSE_RMB 3         // Right mouse button
# define MOUSE_MMB 2         // Middle mouse button
# define MOUSE_SCROLL_UP 4   // Scroll wheel up
# define MOUSE_SCROLL_DOWN 5 // Scroll wheel down

typedef struct s_value
{
	double	x;
	double	y;
}			t_value;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_window;
	char	*fractal_name;
	int		iterations;
	t_img	img;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	double	zoom;
	int		move_mouse;
	int		fract_n;
	int		theme;
}			t_data;

// Parsing Tings
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int i);
double		ft_atof(char *str);
int			chk_val(char *val);
int			check_arg(int ac, char **av, t_data *fractol);

// Error Tings
void		format_error(void);

// Fractal Tings
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		fractal(t_data *fractol, int n);
void		colour_mandelbrot(int x, int y, t_data *fractol);
void		colour_julia(int x, int y, t_data *fractol);
void		colour_burning_ship(int x, int y, t_data *fractol);
double		convert_range(double new_min, double new_max, double value);
void		zoom_fractal(t_data *fractol, int mouse_x, int mouse_y, int key);
int			get_color(int iterations, int theme);

// Event Tings
int			close_fractol(t_data *fractol);
int			handle_keys(int key, t_data *fractol);
void		reset(t_data *fractol);
int			handle_mouse(int key, int mouse_x, int mouse_y, t_data *fractol);
int			move_mouse(int mouse_x, int mouse_y, t_data *fractol);

#endif