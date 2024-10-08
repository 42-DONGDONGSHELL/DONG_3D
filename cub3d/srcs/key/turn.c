/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:22:26 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:27 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	rotate_right(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir.x;
	info->dir.x = info->dir.x * cos(-info->rot_speed) \
					- info->dir.y * sin(-info->rot_speed);
	info->dir.y = old_dir_x * sin(-info->rot_speed) \
					+ info->dir.y * cos(-info->rot_speed);
	old_plane_x = info->plane.x;
	info->plane.x = info->plane.x * cos(-info->rot_speed) \
					- info->plane.y * sin(-info->rot_speed);
	info->plane.y = old_plane_x * sin(-info->rot_speed) \
					+ info->plane.y * cos(-info->rot_speed);
}

void	rotate_left(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir.x;
	info->dir.x = info->dir.x * cos(info->rot_speed) \
					- info->dir.y * sin(info->rot_speed);
	info->dir.y = old_dir_x * sin(info->rot_speed) \
					+ info->dir.y * cos(info->rot_speed);
	old_plane_x = info->plane.x;
	info->plane.x = info->plane.x * cos(info->rot_speed) \
					- info->plane.y * sin(info->rot_speed);
	info->plane.y = old_plane_x * sin(info->rot_speed) \
					+ info->plane.y * cos(info->rot_speed);
}
