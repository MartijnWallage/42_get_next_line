/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:58:28 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/24 12:36:05 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_line(char *line)
{
	if (line)
		free(line);
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
	int	bufferlen;

	bufferlen = linelen(buffer);
	i = 0;
	while (i <= BUFFER_SIZE && buffer[i])
	{
		if (i + bufferlen <= BUFFER_SIZE)
			buffer[i] = buffer[i + bufferlen];
		else
			buffer[i] = 0;
		i++;
	}
}
