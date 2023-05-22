/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:42:10 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/22 17:07:28 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

char	*get_next_line(int fd);
char	*read_fd_into_line(int fd, char *buffer, char *line);
char	*update_buffer(char *buffer);
char	*append_buffer_to_line(char *buffer, char *oldline);
int		lastchar(char *line);
void	*free_all(char *s1, char *s2);
int		ft_linelen(char *s);
void	update_buffer(char *buffer);
char	*init_buffer(char *buffer);
char	*init_line(char *buffer);

#endif