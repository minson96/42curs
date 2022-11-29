/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:14:48 by minson            #+#    #+#             */
/*   Updated: 2022/11/29 13:20:31 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tot_mem;
	size_t	mem_len;
	size_t	i;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	mem_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	tot_mem = (char *)malloc(sizeof(char) * mem_len);
	if (tot_mem == NULL)
		return (0);
	i = -1;
	while (ft_strlen(s1) > ++i)
		tot_mem[i] = s1[i];
	while (mem_len > i)
	{
		tot_mem[i] = *s2;
		*s2++;
		i++;
	}
	tot_mem[i] = '\0';
	return (tot_mem);
}
