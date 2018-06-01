/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:02:58 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:23:27 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				parg(t_lst *dir_l, t_lst *file_l, t_lst *f_l, t_flg *flg)
{
	int				path;
	int				slashen;

	path = 1;
	slashen = 1;
	if (file_l)
		ls_print(file_l, flg, 0);
	if (dir_l && !file_l && !f_l)
	{
		path = dir_l->next ? 1 : 0;
		slashen = 0;
	}
	if (dir_l && !file_l && f_l)
	{
		path = 1;
		slashen = 0;
	}
	while (dir_l)
	{
		if (dir_l->mode[0] == 'd')
			ls_go(dir_l->nm, ls_zero_w(flg), path++, slashen++);
		dir_l = dir_l->next;
	}
}

t_lst				*ls_new_l_farg(char *av)
{
	t_lst			*fail_lst;

	fail_lst = (t_lst *)ft_memalloc(sizeof(t_lst));
	fail_lst->nm = ft_strdup(av);
	fail_lst->fnm = NULL;
	fail_lst->next = NULL;
	return (fail_lst);
}

t_lst				*ls_new_l_arg(char *av, t_flg *flg)
{
	t_lst			*nr_l;

	nr_l = (t_lst *)ft_memalloc(sizeof(t_lst));
	nr_l->nm = ft_strdup(av);
	ls_get_stat(av, nr_l, flg);
	nr_l->fnm = ft_strdup(av);
	nr_l->next = NULL;
	return (nr_l);
}

void				ls_recursion(t_lst *bg_l, t_flg *flg, int cnt_word)
{
	t_lst			*tmp_l;

	if (!flg->one && !flg->l && !flg->g)
		ls_get_column(bg_l, flg, cnt_word);
	else
		ls_print(bg_l, flg, cnt_word);
	tmp_l = bg_l;
	while (flg->hr && tmp_l)
	{
		if (tmp_l->mode[0] == 'd')
			if (ft_strcmp(tmp_l->nm, ".") != 0)
				if (ft_strcmp(tmp_l->nm, "..") != 0)
					ls_go(tmp_l->fnm, ls_zero_w(flg), 1, 1);
		tmp_l = tmp_l->next;
	}
	ls_free_lst(bg_l);
}
