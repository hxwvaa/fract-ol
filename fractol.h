#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_opengl/mlx.h"
// # include <OpenGL/gl.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>

//remove
#include <stdio.h>


#define WIDTH 800
#define HEIGHT 800

#define ITERATION 200

//Keys Linux
#define ESC_KEY_L 65307
#define KEY_LEFT_L       65361  // Left arrow key
#define KEY_RIGHT_L      65363  // Right arrow key
#define KEY_UP_L         65362  // Up arrow key
#define KEY_DOWN_L       65364  // Down arrow key
#define KEY_EQUAL_L      61      // Equals key (=)
#define KEY_MINUS_L      45      // Minus key (-)
#define KEY_SPACE_BAR_L  32      // Space bar
#define KEY_I_L          105     // 'I' key
#define KEY_U_L          117     // 'U' key
#define KEY_P_L          112     // 'P' key

// Keys macOS
#define ESC_KEY_M        53      // Escape key
#define KEY_LEFT_M       123     // Left arrow key
#define KEY_RIGHT_M      124     // Right arrow key
#define KEY_UP_M         126     // Up arrow key
#define KEY_DOWN_M       125     // Down arrow key
#define KEY_EQUAL_M      24      // Equals key (=)
#define KEY_MINUS_M      27      // Minus key (-)
#define KEY_SPACE_BAR_M  49      // Space bar
#define KEY_I_M          34      // 'I' key
#define KEY_U_M          32      // 'U' key
#define KEY_P_M          35      // 'P' key

//Mouse Click/Scroll
# define MOUSE_LMB			1  // Left mouse button
# define MOUSE_RMB			3  // Right mouse button
# define MOUSE_MMB			2  // Middle mouse button
# define MOUSE_SCROLL_UP    4  // Scroll wheel up
# define MOUSE_SCROLL_DOWN  5  // Scroll wheel down

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
	double julia_x;
	double julia_y;
	double zoom;
	int fract_n;
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

int close_fractol(t_data *fractol);
int handle_keys(int key, t_data *fractol);
void zoom_fractal(t_data *fractol, int mouse_x, int mouse_y, int key);
int get_color(int iterations);

int handle_mouse(int key, int mouse_x, int mouse_y, t_data *fractol);

#endif