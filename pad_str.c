#include "ft_printf.h"

void	pad_str(char **str, int pad_len, char c, int left_right)
{
	char *pad;

	pad = ft_strnew(pad_len);
	ft_memset(pad, c, pad_len);
	if (left_right == LEFT)
		*str = ft_strjoin(pad, *str);
	else
		*str = ft_strjoin(*str, pad);
}
