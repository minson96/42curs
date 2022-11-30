/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:13:50 by minson            #+#    #+#             */
/*   Updated: 2022/11/30 16:21:05 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	*word_check(char const *s, char c, int ptr)
{
	int		i;
	int		j;
	int		count;
	char	*word;

	i = ptr;
	j = 0;
	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (count +1));
	if (word == 0)
		return (0);
	i = ptr;
	while (s[i] != c && s[i])
	{
		word[j] = s[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	wd_count;
	char	**str_arr;

	i = 0;
	j = 0;
	wd_count = word_count(s, c);
	str_arr = (char **)malloc(sizeof(char *) * (wd_count +1));
	if (str_arr == 0)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			str_arr[j] = word_check(s, c, i);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	str_arr[j] = 0;
	return (str_arr);
}
