#include "ft_printf.h"

void 	just_str(char **str, int just, char c, int LEFT_RIGHT)
{
	if (just < 0)
		just *= -1;
	if (ft_strlen(*str) >= (size_t)just)
		return ;
	if (LEFT_RIGHT == LEFT)
		pad_str(str, just - ft_strlen(*str), c, RIGHT);
	else
		pad_str(str, just - ft_strlen(*str), c, LEFT);
}
