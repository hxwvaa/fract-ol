#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include "minilibx_opengl/mlx.h"
// #include "minilibx_opengl/mlx_int.h"
// #include "minilibx_opengl/mlx_new_window.h"
// #include "minilibx_opengl/mlx_png.h"
// #include "minilibx_opengl/mlx_opengl.h"

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void format_error(void);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_isdigit(int i);



#endif