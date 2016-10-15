/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 10:17:02 by nbrizini          #+#    #+#             */
/*   Updated: 2014/11/24 11:38:24 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*new;

	if (!alst || !*alst)
		return ;
	list = (*alst);
	new = (*alst)->next;
	ft_lstdelone(&list, del);
	if (new)
		ft_lstdel(&new, del);
	*alst = NULL;
}
