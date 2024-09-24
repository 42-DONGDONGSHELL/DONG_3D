#ifndef PARSE_H
# define PARSE_H

#include "cub3d.h"

// read_file.c
void	read_identifiers(t_info *info, int fd);
void	skip_empty_lines_until_map(int fd, char **buf);
void	process_map_line(t_info *info, char *buf, int y);
void	read_map(t_info *info, int fd);
void	read_cub_file(char *file_path, t_info *info);

// parse.c;
void	parse_rgb(char *buf, int *rgb);
void	init_identifier(int idx, char *buf, t_info *info);

// read_file_util.c;
int		identifier_to_idx(char *line);
void	resize_map_info(t_info *info, int new_height, int new_width, int len);
void	set_player_position(t_info *info, char dir, int x, int y);

#endif