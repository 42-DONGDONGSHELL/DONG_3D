#include "../../includes/cub3d.h"

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

void	is_multi_player(t_info *info)
{
	if (info->loc.x != -1 || info->loc.y != -1)
		error_exit("Error\nMultiple player positions found");
}
