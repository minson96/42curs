/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:08:32 by minson            #+#    #+#             */
/*   Updated: 2022/12/02 12:21:05 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_mem;
	t_list	*now;

	if (lst == 0 || f == 0)
		return (0);
	new_mem = 0;
	while (lst)
	{
		now = ft_lstnew((*f)(lst->content));
		if (now == 0)
		{
			ft_lstclear(&now, del);
			return (0);
		}
		ft_lstadd_back(&new_mem, now);
		lst = lst->next;
	}
	return (new_mem);
}
