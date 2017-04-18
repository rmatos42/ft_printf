#include "ft_printf.h"

int	flag_z(const char *format, int loc)
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

int	flag_plus(const char *format, int loc)
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

int	flag_octo(const char *format, int loc)
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

int	flag_zero(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
	{
		if (ft_atoi(format + i) && format[i] != '0'
				&& format[i] != ' ' && format[i] != '+')
			return (0);
		if (format[i] == '0')
			return (1);
	}
	return (0);
}

int	flag_space(const char *format, int loc)
{
	int	i;
	int	i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == ' ')
			return (1);
	return (0);
}
