#include "../../includes/cub3d.h"

/**
* map의 모든 면이 벽으로 막혀있는지 확인
*/
int	is_valid_map(t_info *info)
{
	(void) info;
	return (0);
}

int	is_identifier_filled(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != ' ')
		{
			ft_putendl_fd("Error\nNot a valid map", STDERR_FILENO);
			exit(1);
		}
		i++;
	}
	return (0);
}

void	is_multi_player(t_info *info)
{
	if (info->loc.x != -1 || info->loc.y != -1)
		error_exit("Error\nMultiple player positions found");
}
