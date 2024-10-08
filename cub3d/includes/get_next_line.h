/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:22:01 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:02 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 32

// get_next_line_utils.c
size_t	gl_strlen(char *s);
char	*gl_strchr(char *s, int c);
char	*gl_strjoin(char *line, char *buff);

// get_next_line.c
char	*ft_get_line(int fd, char *line);
int		get_line_length(char *line);
char	*ft_get_next_line(char *line);
char	*new_line(char *line);
char	*get_next_line(int fd);

#endif
