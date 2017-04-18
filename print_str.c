#include "ft_printf.h"

t_ret	print_str(va_list	args, t_mod mod)
{
	t_ret	ret;

	ret.str = va_arg(args, char*);
	if (ret.str == 0)
		ret.str = "(null)";
	prec_str(&ret.str, mod.prec);
	just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	ret.len = ft_strlen(ret.str);
	return (ret);
}
