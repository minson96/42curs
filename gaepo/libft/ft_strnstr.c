/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:26:16 by minson            #+#    #+#             */
/*   Updated: 2022/11/15 12:37:31 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (len == NULL || needle == NULL)
		return (haystack);
	while (haystack[i] != '/0')
	{
		if (ft_strncmp(haystack + i, needle, len) == 0)
			return (haystack + i);
		i++;
	}
	return (NULL);
}
