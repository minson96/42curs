/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:13:50 by minson            #+#    #+#             */
/*   Updated: 2022/12/03 18:13:12 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

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

static char	*word_check(char const *s, char c, int ptr)
{
	size_t		i;
	size_t		j;
	size_t		count;
	char		*word;

	i = ptr;
	j = 0;
	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (count + 1));
	if (word == 0)
		return (NULL);
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

static void	*is_free(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str_arr;

	i = 0;
	j = 0;
	str_arr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (str_arr == 0)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			str_arr[j] = word_check(s, c, i);
			if (str_arr[j] == NULL)
				return (is_free(str_arr, j));
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	str_arr[j] = 0;
	return (str_arr);
}
