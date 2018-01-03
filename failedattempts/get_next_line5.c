/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 15:14:35 by ttran             #+#    #+#             */
/*   Updated: 2018/01/02 12:30:05 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdowns(const char *str)
{
	int		i;
	char	*s2;

	i = 0;
	while (str[i] != '\0')
		i++;
	i++;
	s2 = malloc(sizeof(char) * i);
	if (!s2)
		return (ft_strnew(0));
	i = 0;
	while (str[i] != '\0')
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

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
	if ((*holder)[0] == '\0')
	{
		free(*holder);
		return (0);
	}
	else
		gtfoline(holder, line);
	return (1);	
}

int		get_next_line(const int fd, char **line)
{
	int br;
	char buffer[BUFF_SIZE + 1];
	static char *arr[FD_LIMIT];
	char *temp;

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
		temp = ft_strjoin(arr[fd], buffer);
		free(arr[fd]);
		arr[fd] = ft_strdowns(temp); 
		free(temp);
	}
	ft_putendl(arr[fd]);
	return (spec_ops_the_line(&arr[fd], line));
}
