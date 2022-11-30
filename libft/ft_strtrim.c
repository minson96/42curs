/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:15:05 by minson            #+#    #+#             */
/*   Updated: 2022/11/30 17:17:18 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;
	size_t	set_len;

	count = 0;
	set_len = sizeof(char) * ft_strlen(set);
	i = 0;
	while (set[i])
	{
		if (ft_strncmp(s1 + i, set, set_len) == 0)
			count++;
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	set_len;
	size_t	i;
	char	*mem;

	mem = NULL;
	i = 0;
	count = 0;
	set_len = sizeof(char) * ft_strlen(set);
	while (s1[i])
	{
		if ((ft_strncmp(s1 + i, set, set_len) == 0) && (count == 0
				|| (count == count_word(s1, set))))
		{	
			i += ft_strlen(set);
			count++;
		}
		else
		{
			*mem = s1[i];
			mem++;
		}
	}
	*mem = '\0';
	return (mem);
}
