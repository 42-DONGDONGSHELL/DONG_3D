#ifndef UTIL_H
# define UTIL_H

# include "cub3d.h"

// simp_util.c
void	*safe_malloc(size_t size);
void	error_exit(char *msg);
void	safe_free(void **ptr);
void	free_2d_array(void **array, int map_height);
void	fill_int_array(int *arr, int size, int val);

// trim_util.c
void	strip_newline(char *str);
char	*trim_spaces(char *str);
char	*trim_rspaces(char *str);
void	trim_edges(int *line, int *start, int *end, int length);

// free_util.c
void	free_all_resources(t_info *info);

#endif
