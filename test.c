#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;

	while(str[i])
		i++;
	return(i);
}
double atod(char *str)
{
	int i;
	int j;
	int num;
	double temp;
	double value;

	i = 0;
	j = 0;
	value = 0.0;
	temp = 0;
	while(str[i] != '.')
	{
		num += str[i] - '0';
		i++;
	}
	value += (double)num;
	i++;
	num = 0;
	printf("%f\n", value);
	while(str[i])
	{
		num += str[i] - '0';
		i++;
	}
	temp = num / 10;
	value += temp;
	return(value);
}

int main(int ac, char **av)
{
	printf("%f", atod(av[1]));
}