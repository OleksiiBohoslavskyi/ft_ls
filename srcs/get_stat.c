/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:38:00 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:21:38 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				*ls_get_time(struct stat stat_orig, t_flg *flg)
{
	char			*date_f;
	char			*date;
	time_t			time_f;
	time_t			time_n;

	time_n = time(NULL);
	date = ft_strnew(12);
	if (flg->l && flg->u)
		ft_memcpy(&time_f, &stat_orig.st_atime, sizeof(stat_orig.st_atime));
	else
		ft_memcpy(&time_f, &stat_orig.st_mtime, sizeof(stat_orig.st_mtime));
	date_f = ctime(&time_f);
	if (time_n - time_f < 15778476 && time_f - time_n < 30)
		ft_memmove(date, (date_f + 4), 12);
	else
	{
		ft_memmove(date, (date_f + 4), 7);
		ft_memmove((date + 7), (date_f + 19), 5);
	}
	return (date);
}

char				ls_filetypeletter(int mode)
{
	char			c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return (c);
}

void				ls_get_mode2(t_lst *new_l, char *path)
{
	acl_t			acl;
	acl_entry_t		entry_p;
	char			*namebuf;
	size_t			size;

	entry_p = NULL;
	namebuf = 0;
	size = 1;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &entry_p) == -1)
		acl_free(&acl);
	if (acl)
		new_l->mode[10] = '+';
	if (listxattr(path, namebuf, size, XATTR_NOFOLLOW) > 0)
		new_l->mode[10] = '@';
}

void				ls_get_mode1(t_lst *new_l, struct stat stat_orig)
{
	new_l->mode = (char *)ft_memalloc(sizeof(char) * 12);
	new_l->mode[0] = ls_filetypeletter(stat_orig.st_mode);
	new_l->mode[1] = (stat_orig.st_mode & S_IRUSR) ? (char)'r' : (char)'-';
	new_l->mode[2] = (stat_orig.st_mode & S_IWUSR) ? (char)'w' : (char)'-';
	new_l->mode[3] = (stat_orig.st_mode & S_IXUSR) ? (char)'x' : (char)'-';
	new_l->mode[4] = (stat_orig.st_mode & S_IRGRP) ? (char)'r' : (char)'-';
	new_l->mode[5] = (stat_orig.st_mode & S_IWGRP) ? (char)'w' : (char)'-';
	new_l->mode[6] = (stat_orig.st_mode & S_IXGRP) ? (char)'x' : (char)'-';
	new_l->mode[7] = (stat_orig.st_mode & S_IROTH) ? (char)'r' : (char)'-';
	new_l->mode[8] = (stat_orig.st_mode & S_IWOTH) ? (char)'w' : (char)'-';
	new_l->mode[9] = (stat_orig.st_mode & S_IXOTH) ? (char)'x' : (char)'-';
	if (stat_orig.st_mode & S_ISUID)
		new_l->mode[3] = (stat_orig.st_mode & S_IXUSR) ? (char)'s' : (char)'S';
	if (stat_orig.st_mode & S_ISGID)
		new_l->mode[6] = (stat_orig.st_mode & S_IXGRP) ? (char)'s' : (char)'l';
	if (stat_orig.st_mode & S_ISVTX)
		new_l->mode[9] = (stat_orig.st_mode & S_IXOTH) ? (char)'t' : (char)'T';
	new_l->link = stat_orig.st_nlink;
	new_l->st_atsp = stat_orig.st_atimespec;
	new_l->st_mtsp = stat_orig.st_mtimespec;
}

void				ls_get_stat(char *path, t_lst *new_l, t_flg *flg)
{
	struct stat		stat_orig;

	if (flg->l || flg->g)
	{
		if ((lstat(path, &stat_orig) == -1) ? ls_error_opendir(path) : 0)
			return ;
	}
	else
	{
		if ((stat(path, &stat_orig) == -1) ? ls_error_opendir(path) : 0)
			return ;
	}
	new_l->blocks = (size_t)stat_orig.st_blocks;
	ls_get_mode1(new_l, stat_orig);
	ls_get_mode2(new_l, path);
	new_l->uid = ft_strdup(getpwuid(stat_orig.st_uid)->pw_name);
	new_l->gid = ft_strdup(getgrgid(stat_orig.st_gid)->gr_name);
	new_l->size = (size_t)stat_orig.st_size;
	new_l->date = ls_get_time(stat_orig, flg);
	if ((new_l->mode[0] == 'c') || (new_l->mode[0] == 'b'))
	{
		new_l->maj = (size_t)major(stat_orig.st_rdev);
		new_l->min = (size_t)minor(stat_orig.st_rdev);
		flg->is = 1;
	}
}
