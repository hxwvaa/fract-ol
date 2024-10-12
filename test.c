#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

double	ft_atof(char *str)
{
	int		i;
	int		j;
	double	value;
	double	sign;

	i = 0;
	j = 10;
	sign = 1.0;
	value = 0.0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	while (str[i] != '.')
		value = value * 10 + (double)(str[i++] - '0');
	i++;
	while (str[i])
	{
		value += (double)(str[i++] - '0') / j;
		j *= 10;
	}
	return (sign * value);
}

int	main(int ac, char **av)
{
	(void)ac;
	printf("%f", ft_atof(av[1]));
}

int	get_color(int iterations, int theme)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iterations / 10;
	if (theme == 1)
	{
		return ((((int)(255 * (t * 3)) % 256) * 65536) + (((int)(255 * (t * 5))
					% 256) * 256) + (int)(255 * (t * 7)) % 256);
		// red = (int)(255 * (t * 3)) % 256;
		// green = (int)(255 * (t * 5)) % 256;
		// blue = (int)(255 * (t * 7)) % 256;
	}
	else if (theme == 2)
	{
		red = (int)(255 * (t * 25)) % 256;
		green = (int)(255 * (t * 23)) % 256;
		blue = (int)(255 * (t * 27)) % 256;
	}
	else if (theme == 3)
	{
		red = (int)(255 * (t * 14)) % 256;
		green = (int)(255 * (t * 12)) % 256;
		blue = (int)(255 * (t * 16)) % 256;
	}
	else
		red = green = blue = (int)(255 * t);
	return ((red * 65536) + (green * 256) + blue);
}
