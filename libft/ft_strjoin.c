/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:14:48 by minson            #+#    #+#             */
/*   Updated: 2022/11/24 17:04:53 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tot_str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = len1 + ft_strlen(s2);
	if (!(tot_str = (char *)malloc(sizeof(char) * (len2 + 1))))
		return (NULL);
	while (len2 > len1)
	{
		
	}
}
