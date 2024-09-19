#include "../../includes/cub3d.h"

// arr idx = 동(0), 서(1), 남(2), 북(3), 천장(4), 바닥(5)
int	read_identifiers(t_info *info, int fd)
{
	int		arr[6];
	int		idx;
	char	*buf;

	ft_memset(arr, 0, sizeof(arr));
	info->texture.f_rgb = safe_malloc(sizeof(int) * 3);
	info->texture.c_rgb = safe_malloc(sizeof(int) * 3);
	buf = NULL;
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL || is_identifier_filled(arr, 6))
			break ;
		idx = identifier_to_idx(buf);
		if (idx == -1)
			continue ;
		arr[idx] = 1;
		init_identifier(idx, buf, info);
		free(buf);
	}
	free(buf);
	if (!is_identifier_filled(arr, 6))
		error_exit("Error\nWrong identifiers");
	return (0);
}

int	read_map(t_info *info, int fd)
{
	char	*buf;
	int		x;
	int		y;
	int		len;

	y = 0;
	info->loc = (t_xy){-1, -1};
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		strip_newline(buf);
		len = ft_strlen(buf);
		if (len > info->width)
			info->width = len;
		resize_map_info(info, y + 1, info->width);
		x = 0;
		while (x < len)
		{
			if (buf[x] == '1')
				info->map_info[y][x] = 1;
			else if (buf[x] == '0' || buf[x] == ' ')
				info->map_info[y][x] = 0;
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
		y++;
		free(buf);
	}
	free(buf);
	if (info->loc.x == -1 || info->loc.y == -1)
		error_exit("Error\nPlayer start position not found");
	info->height = y;
	return (0);
}

int	read_cub_file(char *file_path, t_info *info)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nUnable to open file");
	read_identifiers(info, fd);
	read_map(info, fd);
	close(fd);
	return (0);
}
