#include "ft_printf.h"

int		main(int argc, char **argv)
{
	printf("%zu%zu\n", 0, 18446744073709551615);
	ft_printf("%zu%zu\n", 0, 18446744073709551615);
}
