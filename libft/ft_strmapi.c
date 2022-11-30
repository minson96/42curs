/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:14:57 by minson            #+#    #+#             */
/*   Updated: 2022/11/30 16:24:48 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr_s;
	size_t	i;

	i = 0;
	ptr_s = (char *)s;
	while (ptr_s[i] != 0)
	{
		f(i, ptr_s[i]);
		i++;
	}
	return (ptr_s);
}
