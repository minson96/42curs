/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:09:18 by minson            #+#    #+#             */
/*   Updated: 2023/07/09 15:00:22 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*cut_line(char **storage_line)
{
	int		idx;
	char	*front_line;
	char	*temp_line;

	idx = 0;
	while ((*storage_line)[idx] != '\n')
		idx++;
	temp_line = *storage_line;
	front_line = ft_substr(temp_line, 0, idx + 1);
	*storage_line = ft_strdup(&(*storage_line)[idx + 1]);
	free(temp_line);
	return (front_line);
}

static int	read_and_check(int fd, char **storage_line, char **insert_line)
{
	int		idx;
	int		data_len;
	char	*temp_line;

	data_len = 1;
	while (data_len != 0)
	{
		idx = 0;
		while ((*storage_line)[idx] != '\0')
		{
			if ((*storage_line)[idx] == '\n')
				break ;
			idx++;
		}
		if ((*storage_line)[idx] == '\n')
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
	int		idx;
	int		data_len;
	char	*last_line;

	idx = 0;
	data_len = read_and_check(fd, storage_line, insert_line);
	if (**storage_line == 0 || data_len == -1)
	{
		free(*storage_line);
		*storage_line = NULL;
		return (NULL);
	}
	while ((*storage_line)[idx] != '\0')
	{
		if ((*storage_line)[idx] == '\n')
			break ;
		idx++;
	}
	if ((*storage_line)[idx] == '\n')
		return (cut_line(storage_line));
	last_line = ft_strdup(*storage_line);
	free(*storage_line);
	*storage_line = NULL;
	return (last_line);
}

char	*get_next_line(int fd)
{
	static char	*storage_line[260];
	char		*insert_line;
	char		*out_line;

	if (BUFFER_SIZE <= 0 || (fd < 0 || fd > 259))
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
