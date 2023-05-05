/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:14:48 by minson            #+#    #+#             */
/*   Updated: 2022/12/03 16:37:55 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tot_mem;
	size_t	mem_len;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (ft_strdup(""));
	mem_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	tot_mem = (char *)malloc(sizeof(char) * mem_len);
	if (tot_mem == NULL)
		return (0);
	ft_strlcpy(tot_mem, s1, ft_strlen(s1) + 1);
	ft_strlcat(tot_mem + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (tot_mem);
}
