#include "../../includes/cub3d.h"

void check_empty_after_map(int fd)
{
    char *buf;

    while (1)
    {
        buf = get_next_line(fd);
        if (buf == NULL)
            break;
        strip_newline(buf);
        if (ft_strlen(buf) != 0)
            error_exit("Error\nInvalid input");
        safe_free((void **)&buf);
    }
}

int	check_valid_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != ' ' && line[i] != '\t')
			error_exit("Error\nNot a valid map");
		i++;
	}
	return (0);
}

int	is_valid_map_line(char *line)
{
	int	i;

	i = 0;
	trim_rspaces(line);
	if (ft_strlen(line) == 0)
		return (0);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

/**
* map의 모든 면이 벽으로 막혀있는지 확인
* player 정상적으로 하나 있는지 확인.
*/
int	is_valid_map(t_info *info)
{
	(void) info;
	if (info->loc.x == -1 || info->loc.y == -1)
		error_exit("Error\nPlayer start position not found");
	return (0);
}
