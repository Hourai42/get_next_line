/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 15:14:35 by ttran             #+#    #+#             */
/*   Updated: 2017/12/31 18:05:05 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gtfoline(char *holder, char **line)
{
	char *tmp;
	int i;
	int n;

	n = 0;
	i = 0;
	ft_putstr("Check the beginning of gtfoline\n");
	free(*line);
	while (holder[i] != '\n' && holder[i] != '\0')
		i++;
	*line = malloc(sizeof(char) * (i + 1));
	*line[i] = '\0';
	i = 0;
	while (holder[i] != '\n' && holder[i] != '\0')
	{
		*line[i] = holder[i];
		i++;
	}
	tmp = malloc(sizeof(char) * ((ft_strlen(holder) - i) + 1)); 
	i++;
	while (holder[i] != '\0')
		tmp[n++] = holder[i++];
	tmp[n] = '\0';
	free(holder);
	holder = ft_strdup(tmp);
	free(tmp);
}

int		spec_ops_the_line(char *holder, char **line)
{
	 ft_putstr("Check the beginning of spec ops\n");
	if (ft_strchr(holder, '\n') != NULL)
	{
		gtfoline(holder, line);
		return (1);
	}
	else
		gtfoline(holder, line);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int br;
	char buffer[BUFF_SIZE + 1];
	static char *arr[FD_LIMIT];

	ft_putstr("Check the beginning of GNL\n");
	if (fd == -1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	*line = malloc(sizeof(char) * 42);
	if (!(arr[fd]))
		arr[fd] = ft_strnew(0); 
	while (ft_strchr(arr[fd], '\n') == NULL && br != 0)
	{
		br = read(fd, buffer, BUFF_SIZE);
		buffer[br] = '\0';
		arr[fd] = ft_strjoin(arr[fd], buffer);
	}
	return (spec_ops_the_line(arr[fd], line));
}
