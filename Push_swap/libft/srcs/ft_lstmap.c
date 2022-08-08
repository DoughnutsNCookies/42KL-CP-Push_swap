/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:55:09 by schuah            #+#    #+#             */
/*   Updated: 2022/07/05 19:42:40 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*head;

	if (!lst)
		return (NULL);
	newlist = ft_lstnew((*f)(lst->content));
	if (newlist == NULL)
		return (NULL);
	(void)(*del);
	lst = lst->next;
	head = newlist;
	while (lst != NULL)
	{
		newlist->next = ft_lstnew((*f)(lst->content));
		newlist = newlist->next;
		if (newlist == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (head);
}
