#include "ft_printf.h"

void 	print_mod(t_mod mod)
{
	printf("mod.just:	%i\n", mod.just);
	printf("mod.prec:	%i\n", mod.prec);
	printf("mod.hh:		%i\n", mod.hh);
	printf("mod.h:		%i\n", mod.h);
	printf("mod.ll:		%i\n", mod.ll);
	printf("mod.l:		%i\n", mod.l);
	printf("mod.j:		%i\n", mod.j);
	printf("mod.z:		%i\n", mod.z);
	printf("mod.plus:	%i\n", mod.plus);
	printf("mod.octo:	%i\n", mod.octo);
	printf("mod.zero:	%i\n", mod.zero);
}

t_mod	make_mod(const char *format, int loc)
{
	t_mod	mod;

	mod.just = get_just(format, loc);
	mod.prec = get_prec(format, loc);
	mod.hh = flag_hh(format, loc);
	mod.h = flag_h(format, loc);
	mod.ll = flag_ll(format, loc);
	mod.l = flag_l(format, loc);
	mod.j = flag_j(format, loc);
	mod.z = flag_z(format, loc);
	mod.plus = flag_plus(format, loc);
	mod.octo = flag_octo(format, loc);
	mod.zero = flag_zero(format, loc);
	mod.space = flag_space(format, loc);
	return (mod);
}
