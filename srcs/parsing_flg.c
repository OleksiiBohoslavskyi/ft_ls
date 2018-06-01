/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:48:47 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:21:56 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_flg				*ls_init_flg(t_flg *flg)
{
	flg = (t_flg *)malloc(sizeof(t_flg));
	flg->l = 0;
	flg->x = 0;
	flg->one = 0;
	flg->a = 0;
	flg->r = 0;
	flg->hr = 0;
	flg->t = 0;
	flg->hs = 0;
	flg->f = 0;
	flg->g = 0;
	flg->hg = 0;
	flg->u = 0;
	flg->blocks = 0;
	flg->w_md = 12;
	flg->w_lnk = 0;
	flg->w_uid = 0;
	flg->w_gid = 0;
	flg->is = 0;
	flg->w_mj = 0;
	flg->w_sz = 0;
	flg->w_nm = 0;
	return (flg);
}

void				ls_err_flg(char c)
{
	write(2, "ft_ls: illegal option -- ", 25);
	write(2, &c, 1);
	write(2, "\n", 1);
	write(2, "usage: ft_ls [-autflgGrRS1x] [file ...]\n", 40);
	exit(0);
}

int					ls_is_flg(char c, int i)
{
	char			*s;

	s = "autflgGrRS1x";
	while (s[i] != '\0')
		if (s[i++] == c)
			return (1);
	return (0);
}

void				ls_read_flg(char *av, t_flg *flg)
{
	int				j;

	j = 0;
	while (av[++j] != '\0')
	{
		if (av[j] == '-' && av[j + 1] == '\0')
			continue;
		(av[j] == 'l') ? flg->l = 1 : 0;
		(av[j] == 'x') ? flg->x = 1 : 0;
		(av[j] == '1') ? flg->one = 1 : 0;
		(av[j] == 'a') ? flg->a = 1 : 0;
		(av[j] == 'r') ? flg->r = 1 : 0;
		(av[j] == 'R') ? flg->hr = 1 : 0;
		(av[j] == 't') ? flg->t = 1 : 0;
		(av[j] == 'S') ? flg->hs = 1 : 0;
		(av[j] == 'f') ? flg->f = 1 : 0;
		(av[j] == 'g') ? flg->g = 1 : 0;
		(av[j] == 'G') ? flg->hg = 1 : 0;
		(av[j] == 'u') ? flg->u = 1 : 0;
		if (!ls_is_flg(av[j], 0))
			ls_err_flg(av[j]);
	}
}

int					ls_parsing_flg(char **av, t_flg *flg, int i)
{
	while (av[++i] && (av[i][0] == '-') && (av[i][1] != '\0'))
		ls_read_flg(av[i], flg);
	return (i);
}
