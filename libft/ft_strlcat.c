/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:57:09 by minson            #+#    #+#             */
/*   Updated: 2022/12/03 16:37:22 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(dst);
	if (dstsize > ft_strlen(dst))
	{
		while (dst[i])
			i++;
		while (src[j] && (j + i + 1 < dstsize))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
		return (k + ft_strlen(src));
	}
	else
		return (ft_strlen(src) + dstsize);
}
