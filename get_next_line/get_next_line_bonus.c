/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:09:18 by minson            #+#    #+#             */
/*   Updated: 2023/03/26 16:05:48 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tot_mem;
	size_t	mem_len;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (ft_strdup(""));
	mem_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	tot_mem = (char *)malloc(sizeof(char) * mem_len);
	if (tot_mem == NULL)
		return (0);
	ft_strlcpy(tot_mem, s1, ft_strlen(s1) + 1);
	ft_strlcat(tot_mem + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (tot_mem);
}

static char	*cut_line(char **storage_line)
{
	int		idx3;
	char	*front_line;
	char	*temp_line;

	idx3 = 0;
	while ((*storage_line)[idx3] != '\n')
		idx3++;
	temp_line = *storage_line;
	front_line = ft_substr(temp_line, 0, idx3 + 1);
	*storage_line = ft_strdup(&(*storage_line)[idx3 + 1]);
	free(temp_line);
	return (front_line);
}

static int	check_read(int fd, char **storage_line, char **insert_line)
{
	int		idx2;
	int		data_len;
	char	*temp_line;

	data_len = 1;
	while (data_len != 0)
	{
		idx2 = 0;
		while ((*storage_line)[idx2] != '\0')
		{
			if ((*storage_line)[idx2] == '\n')
				break ;
			idx2++;
		}
		if ((*storage_line)[idx2] == '\n')
			break ;
		data_len = read(fd, *insert_line, BUFFER_SIZE);
		if (data_len == -1)
			return (data_len);
		(*insert_line)[data_len] = '\0';
		temp_line = *storage_line;
		*storage_line = ft_strjoin(temp_line, *insert_line);
		free(temp_line);
	}
	return (data_len);
}

static char	*up_line(int fd, char **storage_line, char **insert_line)
{
	int		idx1;
	int		data_len;
	char	*last_line;

	idx1 = 0;
	data_len = check_read(fd, storage_line, insert_line);
	if (**storage_line == 0 || data_len == -1)
	{
		free(*storage_line);
		*storage_line = NULL;
		return (NULL);
	}
	while ((*storage_line)[idx1] != '\0')
	{
		if ((*storage_line)[idx1] == '\n')
			break ;
		idx1++;
	}
	if ((*storage_line)[idx1] == '\n')
		return (cut_line(storage_line));
	last_line = ft_strdup(*storage_line);
	free(*storage_line);
	*storage_line = NULL;
	return (last_line);
}

char	*get_next_line(int fd)
{
	static char	*storage_line[257];
	char		*insert_line;
	char		*out_line;

	if (BUFFER_SIZE <= 0 || (fd < 0 || fd > 256))
		return (NULL);
	insert_line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (insert_line == NULL)
		return (NULL);
	if (storage_line[fd] == NULL)
		storage_line[fd] = ft_strdup("");
	out_line = up_line(fd, &storage_line[fd], &insert_line);
	free(insert_line);
	return (out_line);
}
