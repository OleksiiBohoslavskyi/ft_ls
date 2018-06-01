/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:28:44 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:23:01 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_lst				*ls_sort_size(t_lst *new_l, t_lst *bg_l)
{
	t_lst			*tmp_l;

	if (bg_l == NULL ? bg_l = new_l : 0)
		return (bg_l);
	tmp_l = bg_l;
	if (tmp_l->size >= new_l->size)
	{
		if (tmp_l->size == new_l->size)
			return (ls_while_minus1(tmp_l, new_l, bg_l));
		else
		{
			while (tmp_l->next && (tmp_l->next->size > new_l->size))
				tmp_l = tmp_l->next;
			if (tmp_l->next && (tmp_l->next->size == new_l->size)
				&& (ft_strcmp(tmp_l->next->nm, new_l->nm) < 0))
			{
				tmp_l = tmp_l->next;
				return (ls_while_minus2(tmp_l, new_l, bg_l));
			}
			else
				return (ls_while_minus3(tmp_l, new_l, bg_l));
		}
	}
	else
		return (ls_lstaddfront4(&bg_l, new_l));
}

t_lst				*ls_while_minus1(t_lst *tmp_l, t_lst *new_l, t_lst *beg_l)
{
	if (ft_strcmp(tmp_l->nm, new_l->nm) < 0)
	{
		while (tmp_l->next && (tmp_l->next->size == new_l->size)
				&& (ft_strcmp(tmp_l->next->nm, new_l->nm) < 0))
			tmp_l = tmp_l->next;
		new_l->next = tmp_l->next;
		tmp_l->next = new_l;
		return (beg_l);
	}
	else
		return (ls_lstaddfront4(&beg_l, new_l));
}

t_lst				*ls_while_minus2(t_lst *tmp_l, t_lst *new_l, t_lst *beg_l)
{
	if (ft_strcmp(tmp_l->nm, new_l->nm) < 0)
	{
		while (tmp_l->next && (tmp_l->next->size == new_l->size)
				&& (ft_strcmp(tmp_l->next->nm, new_l->nm) < 0))
			tmp_l = tmp_l->next;
		new_l->next = tmp_l->next;
		tmp_l->next = new_l;
		return (beg_l);
	}
	else
	{
		new_l->next = tmp_l->next;
		tmp_l->next = new_l;
		return (beg_l);
	}
}

t_lst				*ls_while_minus3(t_lst *tmp_l, t_lst *new_l, t_lst *beg_l)
{
	new_l->next = tmp_l->next;
	tmp_l->next = new_l;
	return (beg_l);
}

t_lst				*ls_lstaddfront4(t_lst **beg_l, t_lst *new_l)
{
	new_l->next = *beg_l;
	*beg_l = new_l;
	return (*beg_l);
}
