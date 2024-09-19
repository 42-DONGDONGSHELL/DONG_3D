#ifndef UTIL_H
# define UTIL_H

#include "cub3d.h"

void	*safe_malloc(size_t size);
void	strip_newline(char *str);
void	error_exit(char *msg);
char	*trim_spaces(char *str);

#endif