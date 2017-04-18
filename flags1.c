#include "ft_printf.h"

int 	flag_hh(const char *format, int loc)
{
	int	i;
	int	i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == 'h' && format[i + 1] == 'h')
			return (1);
	return (0);
}

int 	flag_h(const char *format, int loc)
{
	int	i;
	int	i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == 'h' && format[i + 1] != 'h' && format[i - 1] != 'h')
			return (1);
	return (0);
}

int 	flag_ll(const char *format, int loc)
{
	int	i;
	int	i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == 'l' && format[i + 1] == 'l')
			return (1);
	return (0);
}

int 	flag_l(const char *format, int loc)
{
	int	i;
	int	i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == 'l' && format[i + 1] != 'l' && format[i - 1] != 'l')
			return (1);
	return (0);
}

int 	flag_j(const char *format, int loc)
{
	int	i;
	int	i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == 'j')
			return (1);
	return (0);
}
