#ifndef VALIDATION_H
# define VALIDATION_H

#include "cub3d.h"

// simp_validation.c
int		is_valid_arg(int argc, char **argv);
int		isdigit_str(char *str);

// file_validation.c
int		is_identifier_filled(int *arr, int size);
void	is_multi_player(t_info *info);
void	check_empty_after_map(int fd);

// map_validation.c

int		is_valid_map_line(char *line);
void	check_valid_map(t_info *info);

#endif