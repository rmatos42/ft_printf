#include "ft_printf.h"

t_ret	print_wstr(va_list	args, t_mod mod)
{
	t_ret ret;

	ret.str = "@@";
	ret.len = 2;
	return (ret);
}

t_ret	print_wchar(va_list	args, t_mod mod)
{
	return (print_char(args, mod));
}
