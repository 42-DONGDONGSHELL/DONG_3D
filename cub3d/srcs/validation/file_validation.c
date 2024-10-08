/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:22:48 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:49 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	check_empty_after_map(int fd)
{
	char	*buf;

	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		strip_newline(buf);
		if (ft_strlen(buf) != 0)
			error_exit("Error\nInvalid input");
		safe_free((void **)&buf);
	}
}
