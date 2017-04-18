#include "ft_printf.h"

int		nb_len(long long value, int base)
{
	int i;

	i = 0;
	i += (value < 0) ? 1 : 0;
	if (value < 0)
		value *= -1;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

char	*ft_ltoa_base(long long value, int base, int is_upper)
{
	char		*result;
	char		*buff;
	long long	nb;
	int			len;

	if (value == 0)
		return ("0");
	len = nb_len(value, base);
	nb = (value < 0) ? value * -1 : value;
	result = ft_strnew(len);
	buff = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";
	while (len--)
	{
		result[len] = buff[nb % base];
		nb /= base;
	}
	result[0] = (value < 0) ? '-' : result[0];
	return (result);
}
