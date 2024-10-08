/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:22:24 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:25 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

int	destroy(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.img);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
		info->key_w = 1;
	else if (key == A)
		info->key_a = 1;
	else if (key == S)
		info->key_s = 1;
	else if (key == D)
		info->key_d = 1;
	else if (key == L)
		info->key_left = 1;
	else if (key == R)
		info->key_right = 1;
	return (0);
}

int	key_release(int key, t_info *info)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
		info->key_w = 0;
	else if (key == A)
		info->key_a = 0;
	else if (key == S)
		info->key_s = 0;
	else if (key == D)
		info->key_d = 0;
	else if (key == L)
		info->key_left = 0;
	else if (key == R)
		info->key_right = 0;
	return (0);
}

void	key_update(t_info *info)
{
	if (info->key_w)
		move_forward(info);
	if (info->key_s)
		move_backward(info);
	if (info->key_d)
		move_right(info);
	if (info->key_a)
		move_left(info);
	if (info->key_right)
		rotate_right(info);
	if (info->key_left)
		rotate_left(info);
	if (info->key_esc)
		destroy(info);
}
