/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:15:05 by minson            #+#    #+#             */
/*   Updated: 2022/12/02 17:23:29 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == set[j])
		{	
			i++;
			j++;
		}
		else
		{
			
		}
		i++;
	}
	return (i);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(s1);
	while (s1[i] == set[j])
	{
		j++;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*tot_mem;

	tot_mem = NULL;
	i = 0;
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (ft_strnstr(s1, set, (size_t)ft_strlen(set)) != 0)
		return ((char *)s1);
	tot_mem = (char *)malloc(sizeof(char) * (int)(end - start +1));
	if (tot_mem == 0)
		return (NULL);
	i = 0;
	while (start < end)
	{
		tot_mem[i] = s1[start];
		start++;
		i++;
	}
	tot_mem[i] = '\0';
	return (tot_mem);
}
