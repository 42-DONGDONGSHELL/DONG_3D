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
