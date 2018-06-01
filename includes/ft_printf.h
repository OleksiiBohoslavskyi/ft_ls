/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:22:17 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/13 15:42:13 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <string.h>
# include <stddef.h>
# include <locale.h>
# include <wctype.h>

# define BLACK_COLOR        	"\033[22;30m"
# define BLACK     				"{black}"
# define RED_COLOR         		"\033[22;31m"
# define RED       				"{red}"
# define GREEN_COLOR       		"\033[22;32m"
# define GREEN     				"{green}"
# define BROWN_COLOR       		"\033[22;33m"
# define BROWN     				"{brown}"
# define BLUE_COLOR        		"\033[22;34m"
# define BLUE      				"{blue}"
# define BLACK_COLOR_BROWN 		"\033[22;30;43m"
# define BLACKBROWN    			"{blackbrown}"
# define BLUE_COLOR_BROWN 		"\033[22;34;43m"
# define BLUEBROWN    			"{bluebrown}"
# define BLUE_COLOR_CYAN   		"\033[22;34;46m"
# define BLUECYAN      			"{bluecyan}"
# define BLACK_COLOR_GREEN 		"\033[22;30;42m"
# define BLACKGREEN    			"{blackgreen}"
# define MAGENTA_COLOR     		"\033[22;35m"
# define MAGENTA   				"{magenta}"
# define CYAN_COLOR        		"\033[22;36m"
# define CYAN      				"{cyan}"
# define GRAY_COLOR        		"\033[22;37m"
# define GRAY      				"{gray}"
# define DARK_GRAY_COLOR   		"\033[01;30m"
# define DARK_GRAY 				"{dark gray}"
# define LIGHT_RED_COLOR		"\033[01;31m"
# define LIGHT_RED 				"{light red}"
# define LIGHT_GREEN_COLOR		"\033[01;32m"
# define LIGHT_GREEN			"{light green}"
# define LIGHT_YELLOW_COLOR		"\033[01;33m"
# define LIGHT_YELLOW			"{light yellow}"
# define LIGHT_BLUE_COLOR  		"\033[01;34m"
# define LIGHT_BLUE				"{light blue}"
# define LIGHT_MAGENTA_COLOR	"\033[01;35m"
# define LIGHT_MAGENTA 			"{light magenta}"
# define LIGHT_CYAN_COLOR		"\033[01;36m"
# define LIGHT_CYAN    			"{light cyan}"
# define WHITE_COLOR       		"\033[01;37m"
# define WHITE     				"{white}"
# define EOC_COLOR				"\033[0m"
# define EOC        			"{eoc}"

typedef struct	s_flags
{
	int			hs;
	int			zr;
	int			mn;
	int			pl;
	int			sp;
	int			wd;
	int			dt;
	int			pr;
	int			md;
	char		spec;
	int			bt;
}				t_flags;

int				ft_printf(char *s, ...);
char			*fpf_parsing(va_list ap, char *s, t_flags *fl);
void			fpf_start(va_list ap, t_flags *fl);

int				fpf_isspec_c(char c, int i);
int				fpf_is_fl(char c, char *src, int i);
int				fpf_is_digit(char c);
int				fpf_isdigit(char c);
char			*fpf_fill_flags(char *s, t_flags *fl);
char			*fpf_fill_width(va_list ap, char *s, t_flags *fl);
char			*fpf_fill_precision(va_list ap, char *s, t_flags *fl);
void			fpf_chmod(int i, t_flags *fl);
char			*fpf_fill_mod(char *s, t_flags *fl);

void			fpf_putchar(char c, t_flags *fl);
int				fpf_count_n(intmax_t n);
size_t			fpf_count_u(uintmax_t n);
void			fpf_putnbr(intmax_t n, t_flags *fl);
void			fpf_putstr(char *s, t_flags *fl);
t_flags			*fpf_get_struck(void);
void			fpf_clean_struct(t_flags *fl);

int				fpf_atoi(const char *str);

void			fpf_apply_md_b(intmax_t tmp, int z);
char			*fpf_color(char *s, t_flags *fl, int i, int l);
int				fpf_color2(char *s);
int				fpf_color3(char *s);
int				fpf_p_color(char *s);
int				ft_strequ(char const *s1, char const *s2);

void			fpf_apply_md_id(va_list ap, t_flags *fl, intmax_t tmp);
void			fpf_id(t_flags *fl, intmax_t n, int pr_ln, int w_prln);
void			fpf_id2(t_flags *fl, intmax_t n, int pr_ln, int w_prln);
void			fpf_id3(t_flags *fl, intmax_t n, int pr_ln, int w_prln);
void			fpf_id31(t_flags *fl, intmax_t n, int w_prln);
void			fpf_id32(t_flags *fl, intmax_t n, int w_prln);

void			fpf_iddzero(t_flags *fl, int w);
void			fpf_iddzero2(t_flags *fl, int w);
void			fpf_iddzero3(t_flags *fl, int w);
void			fpf_other(t_flags *flags, int i);

void			fpf_apply_md_u(va_list ap, t_flags *fl, uintmax_t tmp, char *s);
void			fpf_u(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_u2(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_u3(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_u31(t_flags *fl, char *s, int w_prln);

void			fpf_uzero(t_flags *fl, int w);
char			*fpf_uitoa(uintmax_t tmp);

void			f_s(va_list ap, t_flags *fl, int l, int wl);
void			f_s2(char *s, t_flags *fl, int l, int wl);
void			f_c(va_list ap, t_flags *fl);
void			f_c2(t_flags *fl, int wl, int c);
void			fpf_s(t_flags *fl);

void			fpf_apply_md_xx(va_list ap, t_flags *fl);
char			*ito(uintmax_t value, int b, t_flags *fl);

void			fpf_xx(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_xx2(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_xx3(t_flags *fl, char *s, int pr_ln, int w_prln);

char			*fpf_xplushash(char *s, t_flags *fl, int i, int j);

int				fsl(const char *s);

void			fpf_xzero(t_flags *fl, int w);
void			fpf_xzero2(t_flags *fl, int w);

void			fpf_apply_md_oo(va_list ap, t_flags *fl);
char			*it(uintmax_t value, int b, t_flags *fl);
void			fpf_oo(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_oo2(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_oo3(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_oo31(t_flags *fl, char *s, int w_prln);

char			*fpf_oplushash(char *s);
void			fpf_ozero(t_flags *fl, int w);
void			*fpf_memalloc(size_t size);
void			fpf_bzero(void *s, size_t length);

void			f_n(va_list ap, t_flags *fl, int *i);

void			f_p(va_list ap, t_flags *fl, char *s);
void			fpf_p(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_p2(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_p3(t_flags *fl, char *s, int pr_ln, int w_prln);
void			fpf_p31(t_flags *fl, char *s, int w_prln);

char			*fpf_pplushash(char *s, t_flags *fl);
void			fpf_pzero(t_flags *fl, int w);

void			fpf_apply_md_sls(va_list ap, t_flags *fl);
void			fpf_sls(t_flags *fl, char **arr, int l, int i);
void			fpf_sls2(t_flags *fl, char **arr, int l, int i);
void			fpf_ss(t_flags *fl);

int				fpf_sstrlen(wchar_t *c);

void			fpf_apply_md_clc(va_list ap, t_flags *fl);
void			fpf_clc(t_flags *fl, char *s, int i, int wl);
char			*ft_utf(wchar_t c, char *s, char *b);
int				fpf_wint(wchar_t c);

#endif
