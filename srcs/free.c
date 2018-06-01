/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:36:57 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:21:26 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ls_free_lst(t_lst *bg_l)
{
	t_lst		*tmp;

	while (bg_l)
	{
		bg_l->blocks = 0;
		ft_strdel(&bg_l->mode);
		bg_l->link = 0;
		ft_strdel(&bg_l->uid);
		ft_strdel(&bg_l->gid);
		bg_l->size = 0;
		ft_strdel(&bg_l->date);
		ft_strdel(&bg_l->nm);
		if (bg_l->fnm)
			ft_strdel(&bg_l->fnm);
		tmp = bg_l->next;
		free(bg_l);
		bg_l = tmp;
	}
}

void			ls_with_arg(int ac, char **av, t_flg *flg, int i)
{
	struct stat	stat_orig;
	t_lst		*fail_l;
	t_lst		*dir_l;
	t_lst		*file_l;
	t_lst		*tmp_l;

	fail_l = NULL;
	dir_l = NULL;
	file_l = NULL;
	while (++i <= (ac - 1))
	{
		if (-1 != stat(av[i], &stat_orig))
		{
			tmp_l = ls_new_l_arg(av[i], flg);
			ls_get_block_i_width(tmp_l, flg, 0);
			if (tmp_l->mode[0] == 'd')
				dir_l = ls_sort_save(tmp_l, dir_l, flg);
			else
				file_l = ls_sort_save(tmp_l, file_l, flg);
		}
		else
			fail_l = ls_with_arg2(av[i], fail_l, flg);
	}
	ls_w_a3(dir_l, file_l, fail_l, flg);
}

t_lst			*ls_with_arg2(char *av, t_lst *fail_l, t_flg *flg)
{
	if (!flg->f)
		fail_l = ls_sort_alph(ls_new_l_farg(av), fail_l);
	else
		fail_l = ls_sort_f(ls_new_l_farg(av), fail_l);
	return (fail_l);
}

void			ls_w_a3(t_lst *d, t_lst *f, t_lst *e, t_flg *flg)
{
	struct stat	stat_orig;
	t_lst		*tmp_l;

	tmp_l = e;
	while (tmp_l)
	{
		if (-1 == stat(tmp_l->nm, &stat_orig))
			ls_error_opendir(tmp_l->nm);
		tmp_l = tmp_l->next;
	}
	parg(d, f, e, flg);
	if (d)
		free(d);
	if (f)
		ls_free_lst(f);
	if (e)
		ls_free_lst(e);
}
