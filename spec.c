#include "ft_printf.h"

int	get_spec(char c)
{
	int i;

	i = -1;
	while (SPECS[++i])
		if (SPECS[i] == c)
			return (i);
	return (-1);
}

int	spec_loc(const char *format, int loc)
{
	if (format[loc] != '%')
		return (-1);
	while (format[++loc] != '\0')
		if (ft_strchr(SPECS, format[loc]))
			return (loc);
	return (-1);
}
