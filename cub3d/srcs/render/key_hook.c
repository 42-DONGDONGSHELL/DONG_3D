#include "../../includes/render.h"

int destroy(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.img);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}

int		key_press(int key, t_info *info)
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

int		key_release(int key, t_info *info)
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
	{
		if (!info->map_info[(int)(info->loc.x + info->dir.x * info->move_speed)][(int)(info->loc.y)])
			info->loc.x += info->dir.x * info->move_speed;
		if (!info->map_info[(int)(info->loc.x)][(int)(info->loc.y + info->dir.y * info->move_speed)])
			info->loc.y += info->dir.y * info->move_speed;
	}
	//move backwards if no wall behind you
	if (info->key_s)
	{
		if (!info->map_info[(int)(info->loc.x - info->dir.x * info->move_speed)][(int)(info->loc.y)])
			info->loc.x -= info->dir.x * info->move_speed;
		if (!info->map_info[(int)(info->loc.x)][(int)(info->loc.y - info->dir.y * info->move_speed)])
			info->loc.y -= info->dir.y * info->move_speed;
	}
	if (info->key_d)
	{
		// move right by using the perpendicular direction
		double perpDirX = info->dir.y;
		double perpDirY = -info->dir.x;
		if (!info->map_info[(int)(info->loc.x + perpDirX * info->move_speed)][(int)(info->loc.y)])
			info->loc.x += perpDirX * info->move_speed;
		if (!info->map_info[(int)(info->loc.x)][(int)(info->loc.y + perpDirY * info->move_speed)])
			info->loc.y += perpDirY * info->move_speed;
	}
	// move left (A key)
	if (info->key_a)
	{
		// move left by using the perpendicular direction
		double perpDirX = info->dir.y;
		double perpDirY = -info->dir.x;
		if (!info->map_info[(int)(info->loc.x - perpDirX * info->move_speed)][(int)(info->loc.y)])
			info->loc.x -= perpDirX * info->move_speed;
		if (!info->map_info[(int)(info->loc.x)][(int)(info->loc.y - perpDirY * info->move_speed)])
			info->loc.y -= perpDirY * info->move_speed;
	}
	//rotate to the right
	if (info->key_right)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dir.x;
		info->dir.x = info->dir.x * cos(-info->rot_speed) - info->dir.y * sin(-info->rot_speed);
		info->dir.y = oldDirX * sin(-info->rot_speed) + info->dir.y * cos(-info->rot_speed);
		double oldPlaneX = info->plane.x;
		info->plane.x = info->plane.x * cos(-info->rot_speed) - info->plane.y * sin(-info->rot_speed);
		info->plane.y = oldPlaneX * sin(-info->rot_speed) + info->plane.y * cos(-info->rot_speed);
	}
	//rotate to the left
	if (info->key_left)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dir.x;
		info->dir.x = info->dir.x * cos(info->rot_speed) - info->dir.y * sin(info->rot_speed);
		info->dir.y = oldDirX * sin(info->rot_speed) + info->dir.y * cos(info->rot_speed);
		double oldPlaneX = info->plane.x;
		info->plane.x = info->plane.x * cos(info->rot_speed) - info->plane.y * sin(info->rot_speed);
		info->plane.y = oldPlaneX * sin(info->rot_speed) + info->plane.y * cos(info->rot_speed);
	}
	if (info->key_esc)
		destroy(info);
}
