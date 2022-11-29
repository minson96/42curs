/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:14:33 by minson            #+#    #+#             */
/*   Updated: 2022/11/29 17:22:51 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	while ((n > i) && (str1[i] || str2[i]))
	{
		
	}
	return (i);
}
