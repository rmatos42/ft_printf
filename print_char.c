#include "ft_printf.h"

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
