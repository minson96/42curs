/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:15:05 by minson            #+#    #+#             */
/*   Updated: 2022/11/28 16:51:19 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_len;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str_len = ft_strlen(s1) - (ft_strlen(set) * 2);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	while (s1[i])
	{
		j = 0;
		if (s1[i] == set)
		i++;
		j++;
	}
	return (str);
}
