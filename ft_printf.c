#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	char	*str;
	t_mod	mod;
	t_ret	ret;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		mod = make_mod(format, i);
		if (format[i] == '%')
		{
			if (format[spec_loc(format, i)] == '%')
				ret = print_per(mod);
			else
				ret = print[get_spec(format[spec_loc(format, i)])](args, mod);
			ft_putstr(ret.str);
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
	ft_putchar('\0');
	return (len);
}
