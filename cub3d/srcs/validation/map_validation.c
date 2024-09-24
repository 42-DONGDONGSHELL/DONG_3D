#include "../../includes/cub3d.h"

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

void	check_side_walls(int *line, int len)
{
	int	start;
	int	end;

	trim_edges(line, &start, &end, len);
	if (line[start] != 1 || line[end] != 1)
		error_exit("Error\nMap must be surrounded by walls");
}

void	check_first_last_row(int *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 1 && line[i] != 2)
			error_exit("Error\nMap must be surrounded by walls");
		i++;
	}
}

void	check_exit_exist(t_info *info, int i, int j)
{
	if (info->map_info[i][j] == 0)
	{
		if (j + 1 >= info->width || (info->map_info[i][j + 1] != 0 && info->map_info[i][j + 1] != 1))
			error_exit("Error\nInvalid map");

		if (j - 1 < 0 || (info->map_info[i][j - 1] != 0 && info->map_info[i][j - 1] != 1))
			error_exit("Error\nInvalid map");

		if (i + 1 >= info->height || (info->map_info[i + 1][j] != 0 && info->map_info[i + 1][j] != 1))
			error_exit("Error\nInvalid map");
		
		if (i - 1 < 0 || (info->map_info[i - 1][j] != 0 && info->map_info[i - 1][j] != 1))
			error_exit("Error\nInvalid map");
	}
}

void	check_valid_map(t_info *info)
{
	int	i;
	int	j;

	if (info->loc.x == -1 || info->loc.y == -1)
		error_exit("Error\nPlayer start position not found");
	i = 0;
	while (i < info->height)
	{
		if (i == 0 || i == (info->height) - 1)
			check_first_last_row(info->map_info[i]);
		else
		{
			check_side_walls(info->map_info[i], info->width);
			j = 0;
			while (j < info->width)
			{
				check_exit_exist(info, i, j);
				j++;
			}
		}
		i++;
	}
}
