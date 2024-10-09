/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:22:55 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/09 14:47:43 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_textures_paths(t_info *info)
{
	safe_free((void **)&info->texture.n_p);
	safe_free((void **)&info->texture.s_p);
	safe_free((void **)&info->texture.w_p);
	safe_free((void **)&info->texture.e_p);
}

void	free_map_info(t_info *info)
{
	if (info->map_info)
		free_2d_array((void **)info->map_info, info->map_height);
}

void	free_textures(t_info *info)
{
	int	i;

	if (info->tex)
	{
		i = 0;
		while (i < 4)
		{
			safe_free((void **)&info->tex[i]);
			i++;
		}
		safe_free((void **)&info->tex);
	}
}

void	free_buf(t_info *info)
{
	int	i;

	if (info->buf)
	{
		i = 0;
		while (i < HEIGHT)
		{
			safe_free((void **)&info->buf[i]);
			i++;
		}
		safe_free((void **)&info->buf);
	}
}

void	free_all_resources(t_info *info)
{
	free_textures_paths(info);
	free_map_info(info);
	free_textures(info);
	free_buf(info);
}
