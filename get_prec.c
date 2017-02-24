#include "ft_printf.h"

int		get_prec(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == '.')
			return (ft_atoi(format + i + 1));
	return (-1);
}
