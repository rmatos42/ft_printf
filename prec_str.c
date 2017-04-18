#include "ft_printf.h"

void	prec_str(char **str, int prec)
{
	if (prec != -1)
		*str = ft_strsub(*str, 0, prec);
}

void	prec_int(char **str, int prec)
{
	if (ft_strlen(*str) < (size_t)prec && prec != -1)
		pad_str(str, prec - ft_strlen(*str), '0', 0);
}
