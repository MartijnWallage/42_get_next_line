/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:58:28 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/18 15:02:09 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	*free_line(char *line)
{
	if (line)
		free(line);
	line = NULL;
	return (NULL);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	linelen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

void	clean_buffer(char *buffer)
{
	int	i;
	int	j;
	int	bufferlen;

	bufferlen = linelen(buffer);
	i = 0;
	while (i < bufferlen)
	{
		buffer[i] = 0;
		i++;
	}
	j = 0;
	while (i < BUFFER_SIZE && buffer[i])
	{
		buffer[j] = buffer[i];
		buffer[i] = 0;
		i++;
		j++;
	}
}
