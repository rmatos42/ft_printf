// #include "ft_printf.h"

#include <stdlib.h>
char	*wchar_to_str(wchar_t in)
{
	char *str;

	str = malloc(sizeof(char) * 4);
	if (in <= 0x7F)
		str[0] = in;
	else if (in <= 0x7FF)
	{
		str[0] = 192 | (((unsigned int)(in) >> 6) & 63);
		str[1] = 128 | ((unsigned int)(in) & 63);
	}
	else if (in <= 0xFFFF)
	{
		str[0] = 224 | (((unsigned int)(in) >> 12) & 63);
		str[1] = 128 | (((unsigned int)(in) >> 6) & 63);
		str[2] = 128 | ((unsigned int)(in) & 63);
	}
	else if (in <= 0x10FFFF)
	{
		str[0] = 240 | (((unsigned int)(in) >> 18) & 63);
		str[1] = 128 | (((unsigned int)(in) >> 12) & 63);
		str[2] = 128 | (((unsigned int)(in) >> 6) & 63);
		str[3] = 128 | ((unsigned int)(in) & 63);
	}
	str[4] = '\0';
	return (str);
}

#include <stdio.h>
int		main(int argc, char **argv)
{
	wchar_t w = L'😀';
	printf("%s\n", wchar_to_str(w));
	return (0);
}
