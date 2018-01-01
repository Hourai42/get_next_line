/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:52:00 by ttran             #+#    #+#             */
/*   Updated: 2017/12/30 19:07:34 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*startread(int fd, char **line, static char *arr[FD_LIMIT])
{
	char buffer[BUFF_SIZE + 1];
	int br;
	char *tmp;

	while (br = read(fd, buffer, BUFF_SIZE) > 0)
	{
		buffer[buff_size] = '\0';
		if (tmp = ft_strchr(buffer, '\n') != NULL)
		{
			/* Need to ft_strdup the buffer then strchr it */
			tmp++;
			if (tmp != '\0')
				arr[fd] = tmp; 
			/* Need a function to create a new string up to the newline and stop there. */
			/* After that, strjoin will help you for if arr[fd] is already made.
			/* Need another function to constantly call the previous 2 if there's no newline or it's not the end of the read.
			/* Almost there! Once you have these cases, it shouldn't be a problem. Remember to set the buffer to null.   

		}
							
			
	}
	if (br == 0)
	{
		/*A function to deal with the finished case */
	}
}


int	get_next_line(const int fd, char **line)
{
	char buffer[BUFF_SIZE + 1]; 
	static char *arr[FD_LIMIT];

	if (fd == -1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	/*while (read(fd, buffer, BUFF_SIZE) > 0)
	{
		if (ft_strchr(buffer, '\n') != NULL)
			//Case where null character is found, put everything up to newline in string, store pointer to after newline in static arr. 
			//Whenever you loop again, always check if there's already something in the static arr.
			//If there's something in the static arr, strjoin it first and set it to the static char arr before doing anything.
			//Read until first newline character, send that in, then store the rest for the next loop. Need to do for entire buffer? 	
		else if (ft_strchr(buffer, '\n') == NULL)
			//Case where no null character is found, store what is read and move onto next buffer, then strjoin. 
	}*/
	//Above won't work, due to the case where you need to create individuals and send it in. Better to consider each case in separate functions.
	// With arr[fd], you can get rid of the remainders one by one. 
	if (arr[fd])
	{
		
	}
	else
	{
		*line = startread(fd, **line, arr); 				
	}
	/*Have a function to actually create the line? So you can call it constantly until you have a newline. */ 
	/*Think about what to return as well. You need a way to signify that you're done reading the file, but you're simply reading line to line.
	 * You don't always want to be reading from the buffer-- only when you're done appending/reading will you begin to read the next file. */
	//You'll need to use an "if" statement and call it constantly, or use a while and break. Will be easier to use IF statements and call said function over and over again, I believe. 
}
