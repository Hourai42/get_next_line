/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 15:14:35 by ttran             #+#    #+#             */
/*   Updated: 2018/01/01 15:19:30 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gtfoline(char **holder, char **line)
{
	char *tmp;
	int i;
	int n;

	n = 0;
	i = 0;
	free(*line);
	while ((*holder)[i] != '\n' && (*holder)[i] != '\0')
		i++;
	*line = malloc(sizeof(char) * (i + 1));
	(*line)[i] = '\0';
	i = 0;
	while ((*holder)[i] != '\n' && (*holder)[i] != '\0')
	{
		(*line)[i] = (*holder)[i];
		i++;
	}
	tmp = malloc(sizeof(char) * (ft_strlen(*holder) - i)); 
	i++;
	while ((*holder)[i] != '\0')
		tmp[n++] = (*holder)[i++];
	tmp[n] = '\0';
	free(*holder);
	*holder = ft_strdup(tmp);
	free(tmp);
}

int		spec_ops_the_line(char **holder, char **line)
{
	if (ft_strchr(*holder, '\n') != NULL)
	{
		gtfoline(holder, line);
		return (1);
	}
	else
		gtfoline(holder, line);
	free(*holder);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int br;
	char buffer[BUFF_SIZE + 1];
	static char *arr[FD_LIMIT];

	if (fd == -1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	br = 1;
	*line = malloc(sizeof(char) * 42);
	if (!(arr[fd]))
		arr[fd] = ft_strnew(0); 
	while (ft_strchr(arr[fd], '\n') == NULL && br != 0)
	{
		br = read(fd, buffer, BUFF_SIZE);
		buffer[br] = '\0';
		arr[fd] = ft_strjoin(arr[fd], buffer);
	}
	return (spec_ops_the_line(&arr[fd], line));
}
