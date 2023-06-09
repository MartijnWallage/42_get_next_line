/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:42:10 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/18 13:58:08 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*free_line(char *line);
int		max(int a, int b);
int		linelen(char *s);
void	clean_buffer(char *buffer);
char	*init_str(char *buffer);
char	*make_line(char *line, char *buffer, int end);
char	*read_and_write(int fd, char *buffer, char *line);

#endif
