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
	else
		return (-1);
}

void	resize_map_info(t_info *info, int new_height, int new_width)
{
	int	**new_map;
	int	i;

	new_map = (int **)safe_malloc(sizeof(int *) * new_height);
	i = -1;
	while (++i < new_height)
	{
		new_map[i] = (int *)safe_malloc(sizeof(int) * new_width);
		if (i < info->height)
			ft_memcpy(new_map[i], info->map_info[i], sizeof(int) * info->width);
		else
			ft_memset(new_map[i], 0, sizeof(int) * new_width);
	}
	if (info->map_info)
	{
		i = -1;
		while (++i < info->height)
			free(info->map_info[i]);
		free(info->map_info);
	}
	info->map_info = new_map;
	info->height = new_height;
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