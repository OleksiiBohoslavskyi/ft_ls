/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:41:54 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:35:41 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ls_get_block_i_width(t_lst *new_l, t_flg *flg, int v)
{
	flg->blocks += new_l->blocks;
	flg->w_lnk = (l(new_l->link)) > flg->w_lnk ? l(new_l->link) : flg->w_lnk;
	v = ls_strlen(new_l->uid);
	flg->w_uid = (v > flg->w_uid) ? v : flg->w_uid;
	v = ls_strlen(new_l->gid);
	flg->w_gid = (v > flg->w_gid) ? v : flg->w_gid;
	flg->w_mj = ((l(new_l->maj)) > flg->w_mj) ? (l(new_l->maj)) : flg->w_mj;
	flg->w_sz = ((l(new_l->min)) > flg->w_sz) ? (l(new_l->min)) : flg->w_sz;
	flg->w_sz = ((l(new_l->size)) > flg->w_sz) ? (l(new_l->size)) : flg->w_sz;
	v = ls_strlen(new_l->nm);
	flg->w_nm = (v > flg->w_nm) ? v : flg->w_nm;
}

void				ls_get_full_path(const char *path, t_lst *new_l)
{
	char			*full_path;

	full_path = ft_strnew(ft_strlen(path) + ft_strlen(new_l->nm) + 1);
	ft_strcpy(full_path, path);
	if (ft_strcmp(full_path, "/") != 0)
		ft_strcat(full_path, "/");
	ft_strcat(full_path, new_l->nm);
	new_l->fnm = full_path;
}

t_lst				*ls_get_newl(struct dirent *rd, char *path, t_flg *flg)
{
	t_lst			*new_l;

	new_l = (t_lst *)ft_memalloc(sizeof(t_lst));
	new_l->nm = ft_strdup(rd->d_name);
	ls_get_full_path(path, new_l);
	ls_get_stat(new_l->fnm, new_l, flg);
	new_l->next = NULL;
	return (new_l);
}

void				ls_go(char *path, t_flg *flg, int is_1, int is_1arg)
{
	DIR				*d;
	struct dirent	*rd;
	t_lst			*bg_l;
	t_lst			*new_l;
	int				cnt_word;

	cnt_word = 0;
	bg_l = NULL;
	(is_1arg) ? ft_printf("\n") : 0;
	(is_1) ? ft_printf("%s:\n", path) : 0;
	if (((d = opendir(path)) == NULL) ? ls_error_opendir(path) : 0)
		return ;
	while ((rd = readdir(d)) != NULL)
	{
		if (!flg->a && rd->d_name[0] == '.' && !flg->f)
			continue;
		cnt_word++;
		new_l = ls_get_newl(rd, path, flg);
		if (!new_l->date)
			continue;
		ls_get_block_i_width(new_l, flg, 0);
		bg_l = ls_sort_save(new_l, bg_l, flg);
	}
	closedir(d);
	ls_recursion(bg_l, flg, cnt_word);
}

int					main(int ac, char **av)
{
	int				i;
	t_flg			*flg;

	i = 0;
	flg = 0;
	flg = ls_init_flg(flg);
	if (ac > 1)
		i = ls_parsing_flg(av, flg, 0);
	if ((ac == i) || (i == 0))
		ls_go(".", flg, 0, 0);
	else
		ls_with_arg(ac, av, flg, --i);
	free(flg);
	return (0);
}
