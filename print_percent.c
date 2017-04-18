#include "ft_printf.h"

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
