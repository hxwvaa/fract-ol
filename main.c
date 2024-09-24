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

int check_arg(int ac, char **av)
{
	if (ac == 2 && ft_strncmp("mandelbrot", av[1], ft_strlen("mandelbrot")
			+ 1) == 0)
		return(1);
	else if (ac == 4 && ft_strncmp("julia", av[1], ft_strlen("julia") + 1) == 0
		&& (chk_val(av[2]) && chk_val(av[3])))
		return(2);
    //add for bonus
    return(-1);
}

int	main(int ac, char **av)
{
	int n;

	if (ac == 1)
		format_error();
	n = check_arg(ac, av);
    if(n == -1)
        format_error();
    if (n == 1)
        ; //mandelbrot;
    else if(n == 2)
        ; //julia
    else if (n == 3)
        ; //bonus
    
}
