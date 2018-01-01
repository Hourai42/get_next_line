/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:09:39 by ttran             #+#    #+#             */
/*   Updated: 2017/12/30 22:45:46 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	createline(char **line, char *holder)
{
	int i;
	int n;
	char *tmp;

	n = 0;
	i = 0;
	tmp = 0;
	if (*line)
		free(*line);
	if (ft_strchr(holder, '\n') != NULL)
	{	
		while (holder[i] != '\n')
			i++;
		*line = malloc(sizeof(char) * (i + 1));
		(*line)[i] = '\0';
		i = 0;
		while (holder[i] != '\n')
		{
			(*line)[i] = holder[i]; 
			i++;
		}
		n = ft_strlen(holder) - i;
		tmp = malloc(sizeof(char) * n);
		n = 0;
		while (holder[i] != '\0')
			tmp[n++] = holder[i++]; 
		tmp[n] = '\0';
		free(holder);
	 	holder = ft_strdup(tmp);
		free(tmp);	
	}
	else
	{
		*line = ft_strdup(holder);
		free(holder);
	}
}

int		spec_ops_the_line(char **line, char *holder, char buffer[BUFF_SIZE + 1])
{
	holder = ft_strjoin(holder, buffer);
	if (ft_strchr(holder, '\n') != NULL)
	{
		createline(line, holder);
		return (1);
	}
	else
	{
		createline(line, holder);
		return (0);
	}
}

int		get_next_line(const int fd, char **line)
{
	int br;
	char buffer[BUFF_SIZE + 1];
	static char *arr[FD_LIMIT];

	if (fd == -1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	buffer[0] = '\0';
	if (arr[fd])
	{
		if (ft_strchr(arr[fd], '\n') != NULL)
		{
			if (spec_ops_the_line(line, arr[fd], buffer) == 1)
				return (1);
		}
		else
			arr[fd] = ft_strjoin(arr[fd], buffer);
	}
	br = read(fd, buffer, BUFF_SIZE);
	buffer[br] = '\0';
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
	return(spec_ops_the_line(line, arr[fd], buffer));
}
