#include "ft_printf.h"

t_ret	print_int(va_list	args, t_mod mod)
{
	t_ret		ret;
	int			neg;
	long long	nb;

	if (mod.hh)
		nb = va_arg(args, int);
	else if (mod.h)
		nb = va_arg(args, int);
	else if (mod.l)
		nb = va_arg(args, long int);
	else if (mod.ll)
		nb = va_arg(args, long long int);
	else if (mod.j)
		nb = va_arg(args, long long int);
	else if (mod.z)
		nb = va_arg(args, size_t);
	else
		nb = va_arg(args, int);
	neg = 0;
	if (nb < 0)
	{
		nb *= -1;
		neg = 1;
	}
	ret.str = ft_ltoa_base(nb, 10, 0);
	prec_int(&ret.str, mod.prec);
	if (mod.zero && mod.just >= 0 && mod.prec == -1)
		just_str(&ret.str, (mod.plus || neg) ? mod.just - 1 : mod.just, '0', 1);
	if (mod.plus && !neg)
		ret.str = ft_strjoin("+", ret.str);
	else if (neg)
		ret.str = ft_strjoin("-", ret.str);
	else if (mod.space)
		ret.str = ft_strjoin(" ", ret.str);
	if (!(mod.zero && mod.just >= 0 && mod.prec == -1))
		just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	ret.len = ft_strlen(ret.str);
	return (ret);
}

t_ret	print_long(va_list	args, t_mod mod)
{
	t_ret		ret;
	int			neg;
	long long	nb;

	nb = va_arg(args, long int);
	neg = 0;
	if (nb < 0)
	{
		nb *= -1;
		neg = 1;
	}
	ret.str = ft_ltoa_base(nb, 10, 0);
	prec_int(&ret.str, mod.prec);
	if (mod.zero && mod.just >= 0 && mod.prec == -1)
		just_str(&ret.str, (mod.plus || neg) ? mod.just - 1 : mod.just, '0', 1);
	if (mod.plus && !neg)
		ret.str = ft_strjoin("+", ret.str);
	else if (neg)
		ret.str = ft_strjoin("-", ret.str);
	if (!(mod.zero && mod.just >= 0 && mod.prec == -1))
		just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	ret.len = ft_strlen(ret.str);
	return (ret);
}
