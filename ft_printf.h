#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>

# define SPECS "sSpdDioOuUxXcC%"

# define LEFT 0
# define RIGHT 1

typedef	struct	s_mod
{
	int			just;
	int			prec;
	int			hh;
	int			h;
	int			ll;
	int			l;
	int			j;
	int			z;
	int			plus;
	int			octo;
	int			zero;
	int			space;
}				t_mod;

typedef	struct	s_ret
{
	char		*str;
	int			len;
}				t_ret;

int				get_spec(char c);
int				spec_loc(const char *format, int loc);
int				flag_hh(const char *format, int loc);
int				flag_h(const char *format, int loc);
int				flag_ll(const char *format, int loc);
int				flag_l(const char *format, int loc);
int				flag_j(const char *format, int loc);
int				flag_z(const char *format, int loc);
int				flag_plus(const char *format, int loc);
int				flag_octo(const char *format, int loc);
int				flag_zero(const char *format, int loc);
int				flag_space(const char *format, int loc);
t_mod			make_mod(const char *format, int loc);
void			pad_str(char **str, int pad_len, char c, int left_right);
void			just_str(char **str, int just, char c, int left_right);
int				get_just(const char *format, int loc);
int				get_prec(const char *format, int loc);
void			prec_str(char **str, int prec);
void			prec_int(char **str, int prec);
void			print_mod(t_mod mod);
t_ret			print_str(va_list	args, t_mod mod);
t_ret			print_wstr(va_list	args, t_mod mod);
t_ret			print_ptr(va_list	args, t_mod mod);
t_ret			print_int(va_list	args, t_mod mod);
t_ret			print_long(va_list	args, t_mod mod);
t_ret			print_oct(va_list	args, t_mod mod);
t_ret			print_longoct(va_list	args, t_mod mod);
t_ret			print_uint(va_list	args, t_mod mod);
t_ret			print_ulong(va_list	args, t_mod mod);
t_ret			print_hexdown(va_list	args, t_mod mod);
t_ret			print_hexup(va_list	args, t_mod mod);
t_ret			print_char(va_list	args, t_mod mod);
t_ret			print_wchar(va_list	args, t_mod mod);
t_ret			print_per(t_mod mod);
int				uint_len(uintmax_t value, int base);
char			*ft_uitoa_base(uintmax_t value, int base, int is_upper);
int				nb_len(long long value, int base);
char			*ft_ltoa_base(long long value, int base, int is_upper);
char			*ft_ultoa_base(unsigned long long value, int base,
					int is_upper);
int				ft_printf(const char *format, ...);

#endif
