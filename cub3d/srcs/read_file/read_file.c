/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:23:23 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/09 14:58:30 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	read_identifiers(t_info *info, int fd)
{
	int		arr[6];
	int		idx;
	char	*buf;

	ft_memset(arr, 0, sizeof(arr));
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		idx = identifier_to_idx(buf);
		if (idx == -1 || (idx != 6 && arr[idx] != 0))
			error_exit("Error\nInvalid input");
		if (idx != 6)
			arr[idx] = 1;
		init_identifier(idx, buf, info);
		if (is_identifier_filled(arr, 6))
			break ;
		safe_free((void **)&buf);
	}
	safe_free((void **)&buf);
	if (!is_identifier_filled(arr, 6))
		error_exit("Error\nInvalid input");
}

void	skip_empty_lines_until_map(int fd, char **buf)
{
	char	*tmp;

	while (1)
	{
		*buf = get_next_line(fd);
		if (*buf == NULL)
			error_exit("Error\nMap not found or invalid");
		strip_newline(*buf);
		tmp = ft_strdup(*buf);
		if (is_valid_map_line(*buf))
		{
			free(tmp);
			break ;
		}
		if (ft_strlen(tmp) != 0)
			error_exit("Error\nInvalid input");
		safe_free((void **)buf);
		free(tmp);
	}
}

void	process_map_line(t_info *info, char *buf, int y)
{
	int	x;
	int	len;

	len = ft_strlen(buf);
	resize_map_info(info, y + 1, info->map_width, len);
	x = 0;
	while (x < len)
	{
		if (buf[x] == '1')
			info->map_info[y][x] = 1;
		else if (buf[x] == '0')
			info->map_info[y][x] = 0;
		else if (buf[x] == ' ')
			info->map_info[y][x] = 2;
		else if (buf[x] == 'N' || buf[x] == 'S'
			|| buf[x] == 'E' || buf[x] == 'W')
		{
			info->map_info[y][x] = 0;
			set_player_position(info, buf[x], x, y);
		}
		else
			error_exit("Error\nInvalid map character");
		x++;
	}
}

void	read_map(t_info *info, int fd)
{
	char	*buf;
	int		y;

	y = 0;
	buf = NULL;
	info->loc = (t_xy){-1, -1};
	skip_empty_lines_until_map(fd, &buf);
	while (1)
	{
		process_map_line(info, buf, y++);
		safe_free((void **)&buf);
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		strip_newline(buf);
		if (ft_strlen(buf) == 0)
			break ;
	}
	safe_free((void **)&buf);
	info->map_height = y;
}

void	read_cub_file(char *file_path, t_info *info)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nUnable to open file");
	read_identifiers(info, fd);
	read_map(info, fd);
	check_empty_after_map(fd);
	close(fd);
	check_valid_map(info);
}
