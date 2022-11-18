/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:44:56 by minson            #+#    #+#             */
/*   Updated: 2022/11/14 14:36:36 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	s[10] = "stren";
	char	s2[10] = "stren";
	int			s1[10] = {1, 2, 3, 1, 5};

	printf("%d %d %d\n", ft_isalnum('A'), ft_isalnum('e'), ft_isalnum('1'));
	printf("%d %d\n", ft_isalpha('A'), ft_isalpha('3'));
	printf("%d %d\n", ft_isdigit('A'), ft_isdigit('4'));
	printf("%d %d %d\n", ft_isprint(2), ft_isprint(38), ft_isprint(128));
	printf("%d %d %d\n", ft_isascii(12), ft_isascii(-4), ft_isascii(266));
	printf("%lu\n", ft_strlen(s));
	printf("%s\n\n\n", memset(s1, '2', 3 * sizeof(char)));
	/*for (int i = 0; i < 5; i++) {
        printf("[%d]", *(s1 + i));
    }
    printf("\n");*/
	printf("%d %d %d\n", isalnum('A'), isalnum('e'), isalnum('1'));
	printf("%d %d\n", isalpha('A'), isalpha('3'));
	printf("%d %d\n", isdigit('A'), isdigit('4'));
	printf("%d %d %d\n", isprint(2), isprint(38), isprint(128));
	printf("%d %d %d\n", isascii(12), isascii(-4), isascii(266));
	printf("%lu\n", strlen(s));
	printf("%s\n", ft_memset(s1, 2, 3 * sizeof(int)));
	/*for (int i = 0; i < 5; i++) {
        printf("[%d]", *(s1 + i));
    }
	*/
	ft_bzero(s2, 3 * sizeof(char));
	/*for (int i = 0; i < 5; i++) {
        printf("[%d]", *(s2 + i));
    }*/
	
    printf("\n");
}
