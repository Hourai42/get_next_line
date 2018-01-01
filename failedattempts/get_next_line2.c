/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:38:55 by ttran             #+#    #+#             */
/*   Updated: 2017/12/30 19:06:19 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	create_line2(const int fd, char **line, char **arr[FD_LIMIT], int br)
{
	int i;

	i = 0;
	if (*line)
		free(*line);
	while (*arr[fd][i] != '\0') 
		i++;
	*line = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (**arr[fd] != '\0')
	{
		*line[i] = **arr[fd];
		i++;
		((*arr)[fd])++;
	}	
	*line[i] = '\0';
	if (br == 0)
		return (0);
	else
		return (1);
}

int	create_line(const int fd, char **line, char **arr[FD_LIMIT])
{
	int i;

	i = 0;
	if (*line)
		free(*line);
	while (*arr[fd][i] != '\n') 
		i++;
	*line = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (**arr[fd] != '\n')
	{
		*line[i] = **arr[fd];
		i++;
		((*arr)[fd])++;
	}	
	*line[i] = '\0';
	return (1);
}

int spec_ops_the_line(const int fd, char **line, char **arr[FD_LIMIT], char buffer[BUFF_SIZE + 1], int br)
{
	if (buffer)
		*arr[fd] = ft_strjoin(*arr[fd], buffer);
	if (ft_strchr(*arr[fd], '\n') != NULL)
		return(create_line(fd, line, arr)); 	
	else 
		return(create_line2(fd, line, arr, br));
}

int	get_next_line(const int fd, char **line)
{
	static int br;
	char buffer[BUFF_SIZE + 1];
	static char *arr[FD_LIMIT];

	if (fd == -1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	if (arr[fd])
		if (ft_strchr(arr[fd], '\n') != NULL)
			return(spec_ops_the_line(fd, line, &arr, buffer, br));
	if (!(*buffer))
	{
		br = read(fd, buffer, BUFF_SIZE);
		buffer[br] = '\0';
	}
	while (ft_strchr(buffer, '\n') == NULL && br != 0)
	{
		if (!arr[fd])
		{
			arr[fd] = ft_strdup(buffer);
			br = read(fd, buffer, BUFF_SIZE);
			buffer[br] = '\0';
		}
		else
		{
			arr[fd] = ft_strjoin(arr[fd], buffer); 
			br = read(fd, buffer, BUFF_SIZE);
			buffer[br] = '\0';
		}
	}
	return(spec_ops_the_line(fd, line, &arr, buffer, br));	
}
