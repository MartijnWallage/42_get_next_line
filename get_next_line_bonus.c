/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:12:45 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/24 12:47:30 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*append_buffer_to_line(char *buffer, char *oldline)
{
	int		linelen_buffer;
	int		linelen_oldline;
	int		i;
	int		j;
	char	*newline;

	linelen_buffer = ft_linelen(buffer);
	linelen_oldline = ft_linelen(oldline);
	newline = malloc(linelen_buffer + linelen_oldline + 1);
	if (newline == NULL)
		return (NULL);
	newline[linelen_buffer + linelen_oldline] = '\0';
	i = -1;
	while (++i < linelen_oldline)
		newline[i] = oldline[i];
	free(oldline);
	j = -1;
	while (++j < linelen_buffer)
		newline[i + j] = buffer[j];
	update_buffer(buffer);
	return (newline);
}

char	*init_line(char *buffer)
{
	int		linelen;
	int		i;
	char	*line;

	linelen = ft_linelen(buffer);
	line = malloc(linelen + 1);
	if (line == NULL)
		return (NULL);
	line[linelen] = 0;
	i = -1;
	while (++i < linelen)
		line[i] = buffer[i];
	update_buffer(buffer);
	return (line);
}

char	*init_buffer(char *buffer)
{
	int	i;

	if (buffer != NULL)
		return (buffer);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[__FD_SETSIZE];
	char		*line;
	ssize_t		bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= __FD_SETSIZE)
		return (NULL);
	buffer[fd] = init_buffer(buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = init_line(buffer[fd]);
	bytes_read = 1;
	while (bytes_read > 0 && line && line[lastchar(line)] != '\n')
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_strs(&buffer[fd], line));
		buffer[fd][bytes_read] = 0;
		line = append_buffer_to_line(buffer[fd], line);
	}
	if (buffer[fd] && *buffer[fd] == 0)
		free_strs(&buffer[fd], NULL);
	if (line && *line == 0)
		free_strs(&line, NULL);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd1;
	int		fd2;
	int		i;
	char	*str;
	
	fd1 = open("test0.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		printf("fd is -1\n");
		return (1);
	}
	for (i = 0; i < 5; i++)
	{
		str = get_next_line(fd1);
		printf("Output fd %d: \t\t\t\t%s", fd1, str);
		free(str);
		str = get_next_line(fd2);
		printf("Output fd %d: \t\t\t\t%s", fd2, str);
		free(str);
	}
	close(fd1);
	close(fd2);
	return (0);
}*/
