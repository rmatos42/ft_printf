#include "ft_printf.h"
#include "limits.h"

// #include <stdlib.h>

#include <stdio.h>
int		main(int argc, char **argv)
{
	wchar_t w = L'😀';
	int i = ft_printf("ft:%jd\n", LLONG_MIN);
	int x = printf("gcc:%jd\n", LLONG_MIN);
	printf("%i\n", i);
	return (0);
}
