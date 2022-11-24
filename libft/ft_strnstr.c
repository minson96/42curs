/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:26:16 by minson            #+#    #+#             */
/*   Updated: 2022/11/24 13:52:15 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0 || needle == 0)
		return ((char *)haystack);
	while (haystack[i] != 0)
	{
		if (ft_strncmp(haystack + i, needle, len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
