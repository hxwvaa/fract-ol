#include "fractol.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	format_error(void)
{
	ft_putstr_fd("\n\033[31;1mFormat Error!\n", 2);
	ft_putstr_fd("./fractol mandelbrot\n", 2);
	ft_putstr_fd("./fractol julia <value> <value>\n", 2);
	ft_putstr_fd("./fractol burning_ship\n\n\033[0m", 2);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && n > 0)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
