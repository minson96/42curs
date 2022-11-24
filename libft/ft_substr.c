/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:49:17 by minson            #+#    #+#             */
/*   Updated: 2022/11/23 16:22:52 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	j;

	sub_s = NULL;
	j = 0;
	i = start;
	while (s[i] != 0 && j < len)
	{
		sub_s[j] = s[i];
		j++;
		i++;
	}
	return (sub_s);
}
