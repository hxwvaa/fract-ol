#include "fractol.h"
#include <stdio.h>

int chk_val(char *val)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while(val[i])
    {
        if (ft_isdigit(val[i]) || val[i] == '.')
            ;
        else
            return(0);
        if (val[i] == '.')
        {
            if (flag == 1)
                return(0);
            flag = 1;
        }
        i++;
    }
    return(1);
}

char	*check_arg(int ac, char **av)
{
	if (ac == 2 && ft_strncmp("mandelbrot", av[1], ft_strlen("mandelbrot")
			+ 1) == 0)
		return("mandel");
	else if (ac == 4 && ft_strncmp("julia", av[1], ft_strlen("julia") + 1) == 0
		&& (chk_val(av[2]) && chk_val(av[3])))
		return("julia");
    return("error");
}

int	main(int ac, char **av)
{
	char *name;

	if (ac == 1)
		format_error();
	name = check_arg(ac, av);
    if(ft_strncmp("error", name, 5) == 0)
        format_error();
}