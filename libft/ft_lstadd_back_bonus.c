/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:08:53 by minson            #+#    #+#             */
/*   Updated: 2022/12/02 12:21:57 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst == 0 || new == 0)
	{
		return ;
	}
	current = 0;
	if (*lst)
	{
		current = ft_lstlast(*lst);
		current->next = new;
	}
	else
	{
		*lst = new;
	}
}
