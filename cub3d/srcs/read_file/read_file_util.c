#include "../../includes/cub3d.h"

int	identifier_to_idx(char *line)
{
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (2);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (3);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (4);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (5);
	else if (ft_strncmp(line, "\n", 1) == 0)
		return (6);
	else
		return (-1);
}

void	resize_map_info(t_info *info, int new_height, int old_width, int len)
{
	int	**new_map;
	int	i;
	int	longer;

	longer = old_width;
	if (longer < len)
		longer = len;
	new_map = (int **)safe_malloc(sizeof(int *) * new_height);
	i = -1;
	while (++i < new_height)
	{
		new_map[i] = (int *)safe_malloc(sizeof(int) * longer);
		fill_int_array(new_map[i], longer, 2);
		if (i < info->map_height)
			ft_memcpy(new_map[i], info->map_info[i], sizeof(int) * info->map_width);
	}
	if (info->map_info)
		free_2d_array((void **)info->map_info, info->map_height);
	info->map_info = new_map;
	info->map_width = longer;
	info->map_height = new_height;
}

void	set_player_position(t_info *info, char dir, int x, int y)
{
	is_multi_player(info);
	info->loc.x = (double)x;
	info->loc.y = (double)y;
	if (dir == 'N')
		info->dir = (t_xy){0, 1};
	else if (dir == 'S')
		info->dir = (t_xy){0, -1};
	else if (dir == 'E')
		info->dir = (t_xy){1, 0};
	else if (dir == 'W')
		info->dir = (t_xy){-1, 0};
}
