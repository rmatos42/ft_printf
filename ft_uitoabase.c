#include "ft_printf.h"

int		uint_len(uintmax_t value, int base)
{
	int i;

	i = 0;
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

char	*ft_uitoa_base(uintmax_t value, int base, int is_upper)
{
	char	*result;
	char	*buff;
	int		len;

	if (value == 0)
		return ("0");
	len = uint_len(value, base);
	result = ft_strnew(len);
	buff = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";
	while (len--)
	{
		result[len] = buff[value % base];
		value /= base;
	}
	return (result);
}

int		unb_len(unsigned long long value, int base)
{
	int i;

	i = 0;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

char	*ft_ultoa_base(unsigned long long value, int base, int is_upper)
{
	char	*result;
	char	*buff;
	int		len;

	if (value == 0)
		return ("0");
	len = unb_len(value, base);
	result = ft_strnew(len);
	buff = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";
	while (len--)
	{
		result[len] = buff[value % base];
		value /= base;
	}
	return (result);
}
