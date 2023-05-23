/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:58:28 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/23 17:16:08 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_strs(char **buffer, *line)
{
	free(*buffer);
	*buffer = NULL;
	free(line);
	return (NULL);
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

int	ft_linelen(char *s)
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

int	lastchar(char *line)
{
	int	linelen;

	linelen = ft_linelen(line);
	if (linelen > 0)
		return (linelen - 1);
	else
		return (0);
}
