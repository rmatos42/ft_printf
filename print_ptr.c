#include "ft_printf.h"

t_ret	print_ptr(va_list	args, t_mod mod)
{
	t_ret		ret;
	uintmax_t	addr;

	addr = va_arg(args, uintmax_t);
	ret.str = ft_uitoa_base(addr, 16, 0);
	if (!mod.zero || (size_t)mod.just <= ft_strlen(ret.str) + 2)
		ret.str = ft_strjoin("0x", ret.str);
	if (mod.zero && mod.just >= 0 && (size_t)mod.just >= ft_strlen(ret.str) + 2)
	{
		just_str(&ret.str, mod.just, '0', 1);
		ret.str[1] = 'x';
	}
	else
		just_str(&ret.str, mod.just, ' ', (mod.just < 0) ? 0 : 1);
	ret.len = ft_strlen(ret.str);
	return (ret);
}
