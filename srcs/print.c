/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:51:37 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:20:52 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ls_print2(t_lst *tmp_l, t_flg *flg)
{
	int w;
	int v;

	v = 0;
	w = 0;
	if (!flg->a && flg->is)
		v = 1;
	ft_printf("%-*s", flg->w_md, tmp_l->mode);
	ft_printf("%*d ", flg->w_lnk, tmp_l->link);
	if (!flg->g)
		ft_printf("%-*s  ", flg->w_uid, tmp_l->uid);
	ft_printf("%-*s  ", flg->w_gid, tmp_l->gid);
	if ((tmp_l->mode[0] == 'c') || (tmp_l->mode[0] == 'b'))
	{
		ft_printf(" %*d,", flg->w_mj, tmp_l->maj);
		ft_printf("%*d ", flg->w_sz + v, tmp_l->min);
	}
	else
	{
		if (flg->is)
			w = flg->w_mj + 2;
		ft_printf("%*lld ", flg->w_sz + w + v, tmp_l->size);
	}
	ft_printf("%s ", tmp_l->date);
}

void				ls_print(t_lst *bg_l, t_flg *flg, int i)
{
	t_lst			*tmp_l;

	tmp_l = bg_l;
	if ((flg->l || flg->g) && i)
		ft_printf("total %lld\n", flg->blocks);
	while (tmp_l)
	{
		if (flg->l || flg->g)
		{
			ls_print2(tmp_l, flg);
			ls_print3color(tmp_l, flg);
			ls_print_link(tmp_l);
		}
		else
			ls_print3color(tmp_l, flg);
		write(1, "\n", 1);
		tmp_l = tmp_l->next;
	}
}

void				ls_print_link(t_lst *tmp_l)
{
	char			*s;

	if (tmp_l->mode[0] == 'l')
	{
		s = ft_strnew(257);
		readlink(tmp_l->fnm, s, 256);
		ft_printf(" -> %s", s);
		free(s);
	}
}

void				ls_print3color(t_lst *tmp_l, t_flg *flg)
{
	if (flg->hg)
		ls_print3color2(tmp_l);
	else
		ft_printf("%s", tmp_l->nm);
}

void				ls_print3color2(t_lst *tmp_l)
{
	if (tmp_l->mode[0] == 'd')
	{
		if (tmp_l->mode[8] == 'w' && tmp_l->mode[9] == 't')
			ft_printf("{blackgreen}%s{eoc}", tmp_l->nm);
		else if (tmp_l->mode[8] == 'w' && tmp_l->mode[9] != 't')
			ft_printf("{blackbrown}%s{eoc}", tmp_l->nm);
		else
			ft_printf("{blue}%s{eoc}", tmp_l->nm);
	}
	else if (tmp_l->mode[0] == 'l')
		ft_printf("{magenta}%s{eoc}", tmp_l->nm);
	else if (tmp_l->mode[0] == 'c')
		ft_printf("{bluebrown}%s{eoc}", tmp_l->nm);
	else if (tmp_l->mode[0] == 'b')
		ft_printf("{bluecyan}%s{eoc}", tmp_l->nm);
	else if (tmp_l->mode[0] == 's')
		ft_printf("{green}%s{eoc}", tmp_l->nm);
	else if (tmp_l->mode[0] == 'p')
		ft_printf("{brown}%s{eoc}", tmp_l->nm);
	else if (tmp_l->mode[0] == '-' && (tmp_l->mode[3] == 'x'
				|| tmp_l->mode[6] == 'x'))
		ft_printf("{red}%s{eoc}", tmp_l->nm);
	else
		ft_printf("%s", tmp_l->nm);
}
