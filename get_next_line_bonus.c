/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:12:45 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/23 17:17:02 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	update_buffer(char *buffer)
{
	int	linelen;
	int	i;
	int j;

	linelen = ft_linelen(buffer);
	if (linelen == 0)
		return ;
	i = 0;
	while (i < linelen)
	{
		buffer[i] = 0;
		i++;
	}
	j = 0;
	while (i + j <= BUFFER_SIZE)
	{
		buffer[j] = buffer[i + j];
		j++;
	}
}

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

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	buffer[fd] = init_buffer(buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = init_line(buffer[fd]);
	if (line == NULL)
		return (free_strs(&buffer[fd], NULL);
	bytes_read = 1;
	while (bytes_read > 0 && line[lastchar(line)] != '\n')
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			free(buffer[fd]);
			buffer[fd] = NULL;
			return (NULL);
		}
		buffer[fd][bytes_read] = 0;
		line = append_buffer_to_line(buffer[fd], line);
		if (line == NULL)
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
			return (NULL);
		}
	}
	if (*buffer[fd] == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
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