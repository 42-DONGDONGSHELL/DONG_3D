/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:22:28 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:29 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	check_collision(t_info *info, double new_x, double new_y)
{
	if (!info->map_info[(int)(new_x)][(int)(info->loc.y)])
	{
		if (new_x - (int)new_x < WALL_MARGIN)
			info->loc.x = (int)new_x + WALL_MARGIN;
		else if (new_x - (int)new_x > 1 - WALL_MARGIN)
			info->loc.x = (int)new_x + 1 - WALL_MARGIN;
		else
			info->loc.x = new_x;
	}
	if (!info->map_info[(int)(info->loc.x)][(int)(new_y)])
	{
		if (new_y - (int)new_y < WALL_MARGIN)
			info->loc.y = (int)new_y + WALL_MARGIN;
		else if (new_y - (int)new_y > 1 - WALL_MARGIN)
			info->loc.y = (int)new_y + 1 - WALL_MARGIN;
		else
			info->loc.y = new_y;
	}
}

void	move_forward(t_info *info)
{
	double	new_x;
	double	new_y;

	new_x = info->loc.x + info->dir.x * info->move_speed;
	new_y = info->loc.y + info->dir.y * info->move_speed;
	check_collision(info, new_x, new_y);
}

void	move_backward(t_info *info)
{
	double	new_x;
	double	new_y;

	new_x = info->loc.x - info->dir.x * info->move_speed;
	new_y = info->loc.y - info->dir.y * info->move_speed;
	check_collision(info, new_x, new_y);
}

void	move_right(t_info *info)
{
	double	perp_dir_x;
	double	perp_dir_y;
	double	new_x;
	double	new_y;

	perp_dir_x = info->dir.y;
	perp_dir_y = -info->dir.x;
	new_x = info->loc.x + perp_dir_x * info->move_speed;
	new_y = info->loc.y + perp_dir_y * info->move_speed;
	check_collision(info, new_x, new_y);
}

void	move_left(t_info *info)
{
	double	perp_dir_x;
	double	perp_dir_y;
	double	new_x;
	double	new_y;

	perp_dir_x = info->dir.y;
	perp_dir_y = -info->dir.x;
	new_x = info->loc.x - perp_dir_x * info->move_speed;
	new_y = info->loc.y - perp_dir_y * info->move_speed;
	check_collision(info, new_x, new_y);
}
