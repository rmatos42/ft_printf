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

t_ret	print_wstr(va_list	args, t_mod mod)
{
	t_ret ret;

	ret.str = "str";
	ret.len = 3;
	return (ret);
}

t_ret	print_ptr(va_list	args, t_mod mod)
{
	t_ret		ret;
	uintmax_t	addr;

	addr = va_arg(args, uintmax_t);
	ret.str = ft_uitoa_base(addr, 16, 0);
	if (!mod.zero || mod.just <= ft_strlen(ret.str) + 2)
		ret.str = ft_strjoin("0x", ret.str);
	if (mod.zero && mod.just >= 0 && mod.just >= ft_strlen(ret.str) + 2)
	{
		just_str(&ret.str, mod.just, '0', 1);
		ret.str[1] = 'x';
	}
	else
		just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	ret.len = ft_strlen(ret.str);
	return (ret);
}

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
		nb = va_arg(args, intmax_t);
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

t_ret	print_D(va_list	args, t_mod mod)
{
	t_ret		ret;
	int			neg;
	long		nb;

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

t_ret	print_oct(va_list	args, t_mod mod)
{
	t_ret		ret;
	int			neg;
	unsigned long long	nb;

	if (mod.hh)
		nb = va_arg(args, unsigned int);
	else if (mod.h)
		nb = va_arg(args, unsigned int);
	else if (mod.l)
		nb = va_arg(args, unsigned long int);
	else if (mod.ll)
		nb = va_arg(args, unsigned long long int);
	else if (mod.j)
		nb = va_arg(args, uintmax_t);
	else if (mod.z)
		nb = va_arg(args, unsigned long long);
	else
		nb = va_arg(args, unsigned int);
	ret.str = ft_ultoa_base(nb, 8, 0);
	prec_int(&ret.str, mod.prec);
	if (mod.zero && mod.just >= 0 && mod.prec == -1)
	{
		just_str(&ret.str, mod.just, '0', 1);
		ret.str = (mod.octo && nb != 0) ? ft_strjoin("0", ret.str) : ret.str;
	}
	if (!(mod.zero && mod.just >= 0 && mod.prec == -1))
	{
		ret.str = (mod.octo && nb != 0) ? ft_strjoin("0", ret.str) : ret.str;
		just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	}
	ret.len = ft_strlen(ret.str);
	return (ret);
}

t_ret	print_O(va_list	args, t_mod mod)
{
	t_ret ret;

	ret.str = "str";
	ret.len = 3;
	return (ret);
}

t_ret	print_uint(va_list	args, t_mod mod)
{
	t_ret		ret;
	int			neg;
	unsigned long long	nb;

	if (mod.hh)
		nb = va_arg(args, unsigned int);
	else if (mod.h)
		nb = va_arg(args, unsigned int);
	else if (mod.l)
		nb = va_arg(args, unsigned long int);
	else if (mod.ll)
		nb = va_arg(args, unsigned long long int);
	else if (mod.j)
		nb = va_arg(args, uintmax_t);
	else if (mod.z)
		nb = va_arg(args, unsigned long long);
	else
		nb = va_arg(args, unsigned int);
	ret.str = ft_ultoa_base(nb, 10, 0);
	prec_int(&ret.str, mod.prec);
	if (mod.zero && mod.just >= 0 && mod.prec == -1)
		just_str(&ret.str, mod.just, '0', 1);
	if (!(mod.zero && mod.just >= 0 && mod.prec == -1))
		just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	ret.len = ft_strlen(ret.str);
	return (ret);
}

t_ret	print_U(va_list	args, t_mod mod)
{
	t_ret ret;

	ret.str = "str";
	ret.len = 3;
	return (ret);
}

t_ret	print_hexdown(va_list	args, t_mod mod)
{
	t_ret		ret;
	int			neg;
	unsigned long long	nb;

	if (mod.hh)
		nb = va_arg(args, unsigned int);
	else if (mod.h)
		nb = va_arg(args, unsigned int);
	else if (mod.l)
		nb = va_arg(args, unsigned long int);
	else if (mod.ll)
		nb = va_arg(args, unsigned long long int);
	else if (mod.j)
		nb = va_arg(args, uintmax_t);
	else if (mod.z)
		nb = va_arg(args, unsigned long long);
	else
		nb = va_arg(args, unsigned int);
	ret.str = ft_ultoa_base(nb, 16, 0);
	prec_int(&ret.str, mod.prec);
	if (mod.zero && mod.just >= 0 && mod.prec == -1)
	{
		just_str(&ret.str, mod.just, '0', 1);
		ret.str = (mod.octo && nb != 0) ? ft_strjoin("0X", ret.str) : ret.str;
	}
	else
	{
		ret.str = (mod.octo && nb != 0) ? ft_strjoin("0X", ret.str) : ret.str;
		just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	}
	ret.len = ft_strlen(ret.str);
	return (ret);
}

t_ret	print_hexup(va_list	args, t_mod mod)
{
	t_ret		ret;
	int			neg;
	unsigned long long	nb;

	if (mod.hh)
		nb = va_arg(args, unsigned int);
	else if (mod.h)
		nb = va_arg(args, unsigned int);
	else if (mod.l)
		nb = va_arg(args, unsigned long int);
	else if (mod.ll)
		nb = va_arg(args, unsigned long long int);
	else if (mod.j)
		nb = va_arg(args, uintmax_t);
	else if (mod.z)
		nb = va_arg(args, unsigned long long);
	else
		nb = va_arg(args, unsigned int);
	ret.str = ft_ultoa_base(nb, 16, 1);
	prec_int(&ret.str, mod.prec);
	if (mod.zero && mod.just >= 0 && mod.prec == -1)
	{
		just_str(&ret.str, mod.just, '0', 1);
		ret.str = (mod.octo && nb != 0) ? ft_strjoin("0X", ret.str) : ret.str;
	}
	else
	{
		ret.str = (mod.octo && nb != 0) ? ft_strjoin("0X", ret.str) : ret.str;
		just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	}
	ret.len = ft_strlen(ret.str);
	return (ret);
}

t_ret	print_char(va_list	args, t_mod mod)
{
	t_ret	ret;
	char	c;

	if (mod.l)
		return print_wchar(args, mod);
	else
		c = va_arg(args, int);
	ret.str = ft_memalloc(sizeof(char) * 2);
	ret.str[0] = c;
	ret.str[1] = '\0';
	just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	ret.len = ft_strlen(ret.str);
	if (!ret.str[0])
		ret.len++;
	return (ret);
}

char	*wchar_to_str(wchar_t in)
{
	char *str;

	str = malloc(sizeof(char) * 4);
	if (in <= 0x7F)
		str[0] = in;
	else if (in <= 0x7FF)
	{
		str[0] = 192 | (((unsigned int)(in) >> 6) & 63);
		str[1] = 128 | ((unsigned int)(in) & 63);
	}
	else if (in <= 0xFFFF)
	{
		str[0] = 224 | (((unsigned int)(in) >> 12) & 63);
		str[1] = 128 | (((unsigned int)(in) >> 6) & 63);
		str[2] = 128 | ((unsigned int)(in) & 63);
	}
	else if (in <= 0x10FFFF)
	{
		str[0] = 240 | (((unsigned int)(in) >> 18) & 63);
		str[1] = 128 | (((unsigned int)(in) >> 12) & 63);
		str[2] = 128 | (((unsigned int)(in) >> 6) & 63);
		str[3] = 128 | ((unsigned int)(in) & 63);
	}
	str[4] = '\0';
	return (str);
}

t_ret	print_wchar(va_list	args, t_mod mod)
{
	t_ret ret;
	wchar_t	w;

	w = va_arg(args, wchar_t);
	ret.str = wchar_to_str(w);
	ret.len = 1;
	return (ret);
}

t_ret	print_per(t_mod mod)
{
	t_ret	ret;

	ret.str = ft_memalloc(sizeof(char) * 2);
	ret.str[0] = '%';
	ret.str[1] = '\0';
	just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	ret.len = ft_strlen(ret.str);
	return (ret);
}
