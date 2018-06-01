/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:59:27 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:22:42 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ls_lstaddfront(t_lst **bg_l, t_lst *new_l)
{
	new_l->next = *bg_l;
	*bg_l = new_l;
}

t_lst				*ls_sort_ralph(t_lst *new_l, t_lst *bg_l)
{
	t_lst			*tmp_l;

	if (bg_l == NULL ? bg_l = new_l : 0)
		return (bg_l);
	tmp_l = bg_l;
	if (ft_strcmp(tmp_l->nm, new_l->nm) > 0)
	{
		while (tmp_l->next && (ft_strcmp(tmp_l->next->nm, new_l->nm) > 0))
			tmp_l = tmp_l->next;
		new_l->next = tmp_l->next;
		tmp_l->next = new_l;
	}
	else
		ls_lstaddfront(&bg_l, new_l);
	return (bg_l);
}

t_lst				*ls_sort_alph(t_lst *new_l, t_lst *bg_l)
{
	t_lst			*tmp_l;

	if (bg_l == NULL ? bg_l = new_l : 0)
		return (bg_l);
	tmp_l = bg_l;
	if (ft_strcmp(tmp_l->nm, new_l->nm) <= 0)
	{
		while (tmp_l->next && (ft_strcmp(tmp_l->next->nm, new_l->nm) <= 0))
			tmp_l = tmp_l->next;
		new_l->next = tmp_l->next;
		tmp_l->next = new_l;
	}
	else
		ls_lstaddfront(&bg_l, new_l);
	return (bg_l);
}

t_lst				*ls_sort_save(t_lst *new_l, t_lst *bg_l, t_flg *flg)
{
	if (flg->f)
		bg_l = ls_sort_f(new_l, bg_l);
	else if (flg->hs && !flg->r)
		bg_l = ls_sort_size(new_l, bg_l);
	else if (flg->hs && flg->r)
		bg_l = ls_sort_rsize(new_l, bg_l);
	else if (flg->t && !flg->r)
		bg_l = ls_sort_t(new_l, bg_l, flg);
	else if (flg->t && flg->r)
		bg_l = ls_sort_rt(new_l, bg_l, flg);
	else if (!flg->t && flg->r)
		bg_l = ls_sort_ralph(new_l, bg_l);
	else
		bg_l = ls_sort_alph(new_l, bg_l);
	return (bg_l);
}

t_lst				*ls_sort_f(t_lst *new_l, t_lst *bg_l)
{
	t_lst			*tmp_l;

	if (bg_l == NULL ? bg_l = new_l : 0)
		return (bg_l);
	tmp_l = bg_l;
	while (tmp_l->next)
		tmp_l = tmp_l->next;
	tmp_l->next = new_l;
	return (bg_l);
}
