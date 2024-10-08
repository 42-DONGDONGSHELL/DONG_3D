/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:22:43 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:44 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	draw(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int	main_loop(t_info *info)
{
	if (info->key_w || info->key_a || info->key_s || \
		info->key_d || info->key_left || info->key_right)
	{
		ray_cast(info);
		draw(info);
		key_update(info);
	}
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_RELEASE, 0, &key_release, info);
	mlx_hook(info->win, 17, 0, destroy, info);
	return (0);
}

int	init_buf(t_info *info)
{
	int	i;
	int	j;

	info->buf = (int **)safe_malloc(sizeof(int *) * HEIGHT);
	i = 0;
	while (i < HEIGHT)
	{
		info->buf[i] = (int *)safe_malloc(sizeof(int) * WIDTH);
		j = 0;
		while (j < WIDTH)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	init_render_info(t_info *info)
{
	int	tmp;

	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_right = 0;
	info->key_left = 0;
	info->key_esc = 0;
	info->move_speed = 0.02;
	info->rot_speed = 0.02;
	tmp = info->loc.x;
	info->loc.x = info->loc.y;
	info->loc.y = tmp;
	init_buf(info);
	return (0);
}

int	render(t_info *info)
{
	info->mlx = mlx_init();
	init_render_info(info);
	load_texture(info);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx");
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, \
		&info->img.size_l, &info->img.endian);
	ray_cast(info);
	draw(info);
	key_update(info);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_loop(info->mlx);
	return (0);
}
