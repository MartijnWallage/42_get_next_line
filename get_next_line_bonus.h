/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:42:10 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/23 17:16:13 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*append_buffer_to_line(char *buffer, char *oldline);
int		lastchar(char *line);
int		ft_linelen(char *s);
void    *free_strs(char **buffer, char *line);
void	update_buffer(char *buffer);
char	*init_buffer(char *buffer);
char	*init_line(char *buffer);

#endif
