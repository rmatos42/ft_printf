#include "ft_printf.h"

t_ret	handle_spec(const char *format, int i, va_list args)
{
	t_mod mod;
	t_ret ret;

	mod = make_mod(format, i);
	if (format[spec_loc(format, i)] == '%')
		ret = print_per(mod);
	else
		ret = get_function(get_spec(format[spec_loc(format, i)]))(args, mod);
	if (ret.str[0] == '\0' && ret.len == 1)
		ft_putchar('\0');
	ft_putstr(ret.str);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	t_ret	ret;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ret = handle_spec(format, i, args);
			len += ret.len;
			i = spec_loc(format, i) + 1;
		}
		else
		{
			ft_putchar(format[i]);
			len++;
			i++;
		}
	}
	return (len);
}
