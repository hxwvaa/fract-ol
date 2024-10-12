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
