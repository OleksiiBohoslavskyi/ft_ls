/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 12:23:57 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:33:36 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ls_get_column(t_lst *beg_l, t_flg *flg, int c_word)
{
	struct winsize	win;
	unsigned short	w_term;

	w_term = 80;
	isatty(STDIN_FILENO);
	if ((ioctl(STDIN_FILENO, TIOCGWINSZ, &win)) >= 0)
		w_term = win.ws_col;
	if (flg->x)
		ls_pr_xcol(beg_l, flg, w_term / (flg->w_nm + 1));
	else
		ls_pr_col(beg_l, flg, w_term / (flg->w_nm + 1), c_word);
}

void				ls_pr_xcol(t_lst *beg_l, t_flg *flg, int c_col)
{
	int				i;
	int				probel;
	t_lst			*tmp;

	i = 0;
	tmp = beg_l;
	while (tmp)
	{
		while ((i < c_col) && tmp)
		{
			ls_print3color(tmp, flg);
			probel = (flg->w_nm + 1) - ls_strlen(tmp->nm);
			while (probel--)
				write(1, " ", 1);
			i++;
			tmp = tmp->next;
		}
		i = 0;
		write(1, "\n", 1);
	}
}

void				ls_pr_col(t_lst *beg_l, t_flg *flg, int c_col, int c_word)
{
	int				k;
	int				i;
	int				c_wc;
	int				probel;
	t_lst			*tmp;

	k = -1;
	c_wc = c_word / c_col;
	c_wc % 10 ? c_wc++ : 0;
	while (++k < c_wc)
	{
		i = k;
		while (i < c_word)
		{
			tmp = ft_get_tfp(beg_l, i);
			ls_print3color(tmp, flg);
			probel = (flg->w_nm + 1) - ls_strlen(tmp->nm);
			while (probel--)
				write(1, " ", 1);
			i += (c_wc);
		}
		write(1, "\n", 1);
	}
}

t_lst				*ft_get_tfp(t_lst *beg_l, int i)
{
	t_lst			*tmp;
	int				j;

	j = -1;
	tmp = beg_l;
	while (tmp && (++j < i))
		tmp = tmp->next;
	return (tmp);
}
