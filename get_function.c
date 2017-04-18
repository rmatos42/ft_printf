#include "ft_printf.h"

t_ret	(*get_function(int i))(va_list, t_mod)
{
	static t_ret (*print[])(va_list, t_mod) = {print_str, print_wstr, 
		print_ptr, print_int, print_long, print_int, print_oct, 
		print_longoct, print_uint, print_ulong, print_hexdown,
		print_hexup, print_char, print_wchar};

	return (print[i]);
}
