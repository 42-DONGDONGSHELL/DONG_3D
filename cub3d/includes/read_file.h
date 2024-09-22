#ifndef PARSE_H
# define PARSE_H

#include "cub3d.h"

// read_file.c
int		read_identifiers(t_info *info, int fd);
int		read_map(t_info *info, int fd);
int		read_cub_file(char *file_path, t_info *info);

// parse.c;
void	parse_rgb(char *buf, int *rgb);
void	init_identifier(int idx, char *buf, t_info *info);

// read_file_util.c;
int		identifier_to_idx(char *line);
void	resize_map_info(t_info *info, int new_height, int new_width);
void	set_player_position(t_info *info, char dir, int x, int y);

#endif