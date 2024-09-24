#ifndef UTIL_H
# define UTIL_H

#include "cub3d.h"

void	*safe_malloc(size_t size);
void	strip_newline(char *str);
void	error_exit(char *msg);
char	*trim_spaces(char *str);
char	*trim_rspaces(char *str);
void	safe_free(void **ptr);
void	free_2d_array(void **array, int height);

// todo : delete
void print_map(t_info *info);
void print_xy(t_info *info);
void print_identifier_info(t_info *info);

#endif