/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 21:41:01 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 14:21:48 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/ioctl.h>
# include <sys/ttycom.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <termios.h>
# include <stdio.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"

typedef	struct		s_flg
{
	int				l;
	int				x;
	int				one;
	int				a;
	int				r;
	int				hr;
	int				t;
	int				hs;
	int				f;
	int				g;
	int				hg;
	int				u;
	int				blocks;
	int				w_md;
	int				w_lnk;
	int				w_uid;
	int				w_gid;
	int				is;
	int				w_mj;
	int				w_sz;
	int				w_nm;
}					t_flg;

typedef struct		s_lst
{
	size_t			blocks;
	char			*mode;
	size_t			link;
	char			*uid;
	char			*gid;
	size_t			size;
	char			*date;
	size_t			maj;
	size_t			min;
	struct timespec	st_atsp;
	struct timespec	st_mtsp;
	char			*nm;
	char			*fnm;
	struct s_lst	*next;
}					t_lst;

/*
**		parsing_flg.c
*/
t_flg				*ls_init_flg(t_flg *flg);
void				ls_err_flg(char c);
int					ls_is_flg(char c, int i);
void				ls_read_flg(char *av, t_flg *flg);
int					ls_parsing_flg(char **av, t_flg *flg, int i);
/*
**		main.c
*/
void				ls_get_block_i_width(t_lst *new_l, t_flg *flg, int v);
void				ls_get_full_path(const char *path, t_lst *new_l);
t_lst				*ls_get_newl(struct dirent *rd, char *path, t_flg *flg);
void				ls_go(char *path, t_flg *flg, int is_1, int is_1arg);
/*
**		error_opendir.c
*/
t_flg				*ls_zero_w(t_flg *flg);
int					ls_strlen(const char *s);
int					l(size_t n);
char				*ls_get_name_from_path(char *s);
int					ls_error_opendir(char *path);
/*
**		get_stat.c
*/
char				*ls_get_time(struct stat stat_orig, t_flg *flg);
char				ls_filetypeletter(int mode);
void				ls_get_mode2(t_lst *new_l, char *path);
void				ls_get_mode1(t_lst *new_l, struct stat stat_orig);
void				ls_get_stat(char *path, t_lst *new_l, t_flg *flg);
/*
**		sort_save.c
*/
void				ls_lstaddfront(t_lst **bg_l, t_lst *new_l);
t_lst				*ls_sort_ralph(t_lst *new_l, t_lst *bg_l);
t_lst				*ls_sort_alph(t_lst *new_l, t_lst *bg_l);
t_lst				*ls_sort_save(t_lst *new_l, t_lst *bg_l, t_flg *flg);
t_lst				*ls_sort_f(t_lst *new_l, t_lst *bg_l);
/*
**		sort_time.c
*/
int					f(struct timespec b, struct timespec n, t_lst *t, t_lst *m);
int					ls_ch_u(t_lst *tmp_l, t_lst *new_l, t_flg *flg);
t_lst				*ls_sort_t(t_lst *new_l, t_lst *bg_l, t_flg *flg);
t_lst				*ls_sort_rt(t_lst *new_l, t_lst *bg_l, t_flg *flg);
/*
**		print.c
*/
void				ls_print_link(t_lst *tmp_l);
void				ls_print3color2(t_lst *tmp_l);
void				ls_print3color(t_lst *tmp_l, t_flg *flg);
void				ls_print2(t_lst *tmp_l, t_flg *flg);
void				ls_print(t_lst *bbg_l, t_flg *flg, int i);
/*
**		free.c + with_arg.c
*/
void				ls_free_lst(t_lst *bg_l);
void				ls_w_a3(t_lst *d, t_lst *f, t_lst *e, t_flg *flg);
t_lst				*ls_with_arg2(char *av, t_lst *fail_l, t_flg *flg);
void				ls_with_arg(int ac, char **av, t_flg *flg, int i);
/*
**		with_arg.c
*/

void				parg(t_lst *dir_l, t_lst *file_l, t_lst *f_l, t_flg *flg);
t_lst				*ls_new_l_arg(char *av, t_flg *flg);
t_lst				*ls_new_l_farg(char *av);
void				ls_recursion(t_lst *bg_l, t_flg *flg, int cnt_word);
/*
**		sort_rsize.c
*/
t_lst				*ls_while_minus2r(t_lst *tmp_l, t_lst *new_l, t_lst *beg_l);
t_lst				*ls_while_minus1r(t_lst *tmp_l, t_lst *new_l, t_lst *beg_l);
t_lst				*ls_sort_rsize(t_lst *new_l, t_lst *bg_l);
/*
**		sort_size.c
*/
t_lst				*ls_sort_size(t_lst *new_l, t_lst *bg_l);
t_lst				*ls_while_minus1(t_lst *tmp_l, t_lst *new_l, t_lst *beg_l);
t_lst				*ls_while_minus2(t_lst *tmp_l, t_lst *new_l, t_lst *beg_l);
t_lst				*ls_while_minus3(t_lst *tmp_l, t_lst *new_l, t_lst *beg_l);
t_lst				*ls_lstaddfront4(t_lst **beg_l, t_lst *new_l);
/*
**		column.c
*/
void				ls_get_column(t_lst *beg_l, t_flg *flg, int c_word);
void				ls_pr_xcol(t_lst *beg_l, t_flg *flg, int c_col);
void				ls_pr_col(t_lst *beg_l, t_flg *flg, int w_term, int c_word);
t_lst				*ft_get_tfp(t_lst *beg_l, int i);

#endif
