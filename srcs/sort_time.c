/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:00:58 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:23:15 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					f(struct timespec b, struct timespec n, t_lst *t, t_lst *m)
{
	if (b.tv_sec > n.tv_sec)
		return (1);
	if (b.tv_sec < n.tv_sec)
		return (0);
	else
	{
		if (b.tv_nsec > n.tv_nsec)
			return (1);
		if (b.tv_nsec < n.tv_nsec)
			return (0);
		else
			return (ft_strcmp(m->nm, t->nm));
	}
}

int					ls_ch_u(t_lst *tmp_l, t_lst *new_l, t_flg *flg)
{
	if (!flg->u)
		return (f(tmp_l->st_mtsp, new_l->st_mtsp, tmp_l, new_l));
	else
		return (f(tmp_l->st_atsp, new_l->st_atsp, tmp_l, new_l));
}

t_lst				*ls_sort_t(t_lst *new_l, t_lst *bg_l, t_flg *flg)
{
	t_lst			*tmp_l;

	if (bg_l == NULL ? bg_l = new_l : 0)
		return (bg_l);
	tmp_l = bg_l;
	if (ls_ch_u(tmp_l, new_l, flg) > 0)
	{
		while (tmp_l->next && (ls_ch_u(tmp_l->next, new_l, flg) > 0))
			tmp_l = tmp_l->next;
		new_l->next = tmp_l->next;
		tmp_l->next = new_l;
	}
	else
		ls_lstaddfront(&bg_l, new_l);
	return (bg_l);
}

t_lst				*ls_sort_rt(t_lst *new_l, t_lst *bg_l, t_flg *flg)
{
	t_lst			*tmp_l;

	if (bg_l == NULL ? bg_l = new_l : 0)
		return (bg_l);
	tmp_l = bg_l;
	if (ls_ch_u(tmp_l, new_l, flg) <= 0)
	{
		while (tmp_l->next && (ls_ch_u(tmp_l->next, new_l, flg) <= 0))
			tmp_l = tmp_l->next;
		new_l->next = tmp_l->next;
		tmp_l->next = new_l;
	}
	else
		ls_lstaddfront(&bg_l, new_l);
	return (bg_l);
}
