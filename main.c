#include "ft_printf.h"

// #include <stdlib.h>

#include <stdio.h>
int		main(int argc, char **argv)
{
	wchar_t w = L'😀';
	int i = ft_printf("%C\n", w);
	int x = printf("%s\n", wchar_to_str(w));
	printf("%i:%i\n", i, x);
	return (0);
}
