/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:46:27 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/10 15:46:36 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		while ((*alst)->next)
			ft_lstdelone(&((*alst)->next), del);
		ft_lstdelone(alst, del);
		*alst = NULL;
	}
}
