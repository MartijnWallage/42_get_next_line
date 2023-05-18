/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:12:45 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/18 17:28:37 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include "get_next_line.h"

char	*init_str(char *buffer)
{
	int		bufferlen;
	int		i;
	char	*line;

	bufferlen = linelen(buffer);
	line = malloc(bufferlen + 1);
	if (line == NULL)
		return (NULL);
	line[bufferlen] = '\0';
	i = 0;
	while (i < bufferlen)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*make_line(char *line, char *buffer, int end)
{
	char	*new_str;
	int		line_len;
	int		i;
	int		j;

	line_len = linelen(line);
	new_str = malloc(line_len + end + 1);
	if (new_str == NULL)
		return (NULL);
	new_str[line_len + end] = '\0';
	i = 0;
	while (i < line_len)
	{
		new_str[i] = line[i];
		i++;
	}
	free(line);
	j = 0;
	while (i < line_len + end)
	{
		new_str[i] = buffer[j];
		i++;
		j++;
	}
	return (new_str);
}

char	*read_and_write(int fd, char *buffer, char *line)
{
	int	bytes_read;
	int	endline;
	int	lastchar;

	if (line == NULL)
		return (NULL);
	lastchar = max(0, linelen(line) - 1);
	bytes_read = 1;
	while (bytes_read > 0 && line[lastchar] != '\n')
	{
		bytes_read = (int) read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_line(line));
		buffer[bytes_read] = '\0';
		endline = 0;
		while (endline < bytes_read && buffer[endline] != '\n')
			endline++;
		if (buffer[endline] == '\n')
			endline++;
		line = make_line(line, buffer, endline);
		lastchar = max(0, linelen(line) - 1);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[RLIMIT_NOFILE + 2][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > RLIMIT_NOFILE + 2 || BUFFER_SIZE <= 0)
		return (NULL);
	line = init_str(buffer[fd]);
	line = read_and_write(fd, buffer[fd], line);
	clean_buffer(buffer[fd]);
	if (line != NULL && *line == 0)
		return (free_line(line));
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd1;
	int		fd2;
	char	*str1;
	char	*str2;

	fd1 = open("test0.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		printf("fd is -1\n");
		return (1);
	}
	while ((str1 = get_next_line(fd1)) && (str2 = get_next_line(fd2)))
		printf("%s---%s", str1, str2);
	close(fd1);
	close(fd2);
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (0);
}*/
