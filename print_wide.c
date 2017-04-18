#include "ft_printf.h"

t_ret	print_wstr(va_list args, t_mod mod)
{
	return (print_str(args, mod));
}

t_ret	print_wchar(va_list args, t_mod mod)
{
	return (print_char(args, mod));
}
