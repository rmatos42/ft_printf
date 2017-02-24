#include "ft_printf.h"

int		main(int argc, char **argv)
{
	printf("%zu\n", 18446744073709551615);
	ft_printf("%zu\n", 18446744073709551615);
}
