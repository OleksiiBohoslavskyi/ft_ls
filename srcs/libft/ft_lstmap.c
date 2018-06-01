/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:48:24 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/10 15:48:29 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*cur_elem;

	new_lst = NULL;
	if (lst && f)
	{
		new_lst = f(lst);
		cur_elem = new_lst;
		lst = lst->next;
		while (lst)
		{
			cur_elem->next = f(lst);
			cur_elem = cur_elem->next;
			lst = lst->next;
		}
	}
	return (new_lst);
}
