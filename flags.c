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

int 	flag_z(const char *format, int loc)
{
	int	i;
	int	i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == 'z')
			return (1);
	return (0);
}

int 	flag_plus(const char *format, int loc)
{
	int	i;
	int	i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == '+')
			return (1);
	return (0);
}

int 	flag_octo(const char *format, int loc)
{
	int	i;
	int	i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == '#')
			return (1);
	return (0);
}

int 	flag_zero(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
	{
		if (ft_atoi(format + i) && format[i] != '0' && format[i] != ' ' && format[i] != '+')
			return (0);
		if (format[i] == '0')
			return (1);
	}
	return (0);
}
