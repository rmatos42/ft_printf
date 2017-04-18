#include "ft_printf.h"

unsigned long long	get_uint(va_list args, t_mod mod)
{
	if (mod.hh)
		return (va_arg(args, unsigned int));
	else if (mod.h)
		return (va_arg(args, unsigned int));
	else if (mod.l)
		return (va_arg(args, unsigned long int));
	else if (mod.ll)
		return (va_arg(args, unsigned long long int));
	else if (mod.j)
		return (va_arg(args, uintmax_t));
	else if (mod.z)
		return (va_arg(args, unsigned long long));
	else
		return (va_arg(args, unsigned int));
}

t_ret				print_uint(va_list args, t_mod mod)
{
	t_ret				ret;
	unsigned long long	nb;

	nb = get_uint(args, mod);
	ret.str = ft_ultoa_base(nb, 10, 0);
	prec_int(&ret.str, mod.prec);
	if (mod.zero && mod.just >= 0 && mod.prec == -1)
		just_str(&ret.str, mod.just, '0', 1);
	if (!(mod.zero && mod.just >= 0 && mod.prec == -1))
		just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	ret.len = ft_strlen(ret.str);
	return (ret);
}

t_ret				print_ulong(va_list args, t_mod mod)
{
	t_ret				ret;
	unsigned long long	nb;

	nb = va_arg(args, unsigned long long);
	ret.str = ft_ultoa_base(nb, 10, 0);
	prec_int(&ret.str, mod.prec);
	if (mod.zero && mod.just >= 0 && mod.prec == -1)
		just_str(&ret.str, mod.just, '0', 1);
	if (!(mod.zero && mod.just >= 0 && mod.prec == -1))
		just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	ret.len = ft_strlen(ret.str);
	return (ret);
}
