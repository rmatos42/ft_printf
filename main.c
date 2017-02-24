#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int ft = ft_printf("%c\n", 0);
	int gcc = printf("%c\n", 0);

	printf("%i:%i\n", ft, gcc);
}
