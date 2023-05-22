/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:12:45 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/22 17:07:14 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

void	update_buffer(char *buffer)
{
	int	i;
	int	j;
	int	linelen;

	linelen = ft_linelen(buffer);
	i = -1;
	while (++i < linelen)
		buffer[i] = 0;
	j = 0;
	while (i + j < BUFFER_SIZE)
	{
		buffer[j] = buffer[i + j];
		j++;
	}
}

char	*append_buffer_to_line(char *buffer, char *oldline)
{
	char	*newline;
	int		i;
	int		j;
	int		linelen_buffer;
	int		linelen_oldline;

	linelen_buffer = ft_linelen(buffer);
	linelen_oldline = ft_linelen(oldline);
	newline = malloc(linelen_oldline + linelen_buffer + 1);
	if (newline == NULL)
		return (NULL);
	newline[linelen_oldline + linelen_buffer] = '\0';
	i = -1;
	while (++i < linelen_oldline)
		newline[i] = oldline[i];
	free(oldline);
	j = -1;
	while (++j < linelen_buffer)
		newline[i + j] = buffer[j];
	return (newline);
}

char	*read_fd_into_line(int fd, char *buffer, char *line)
{
	int		bytes_read;

	if (line == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && line[lastchar(line)] != '\n')
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = append_buffer_to_line(buffer, line);
		update_buffer(buffer);
	}
	return (line);
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
	line[linelen] = '\0';
	i = 0;
	while (i < linelen)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = init_buffer(buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = init_line(buffer[fd]);
	if (line == NULL)
	{
		free(buffer[fd]);
		return (NULL);
	}
	update_buffer(buffer[fd]);
	line = read_fd_into_line(fd, buffer[fd], line);
	if (line != NULL && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* #include <stdio.h>
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
		printf("%s", str);
		free(str);
		str = get_next_line(fd2);
		printf("\t\t%s", str);
		free(str);
	}
	close(fd1);
	close(fd2);
	return (0);
} */