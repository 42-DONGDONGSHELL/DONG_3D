#include "../../includes/render.h"

void	move_forward(t_info *info)
{
	if (!info->map_info[(int)(info->loc.x + info->dir.x * info->move_speed)] \
						[(int)(info->loc.y)])
		info->loc.x += info->dir.x * info->move_speed;
	if (!info->map_info[(int)(info->loc.x)] \
						[(int)(info->loc.y + info->dir.y * info->move_speed)])
		info->loc.y += info->dir.y * info->move_speed;
}

void	move_backward(t_info *info)
{
	if (!info->map_info[(int)(info->loc.x - info->dir.x * info->move_speed)] \
						[(int)(info->loc.y)])
		info->loc.x -= info->dir.x * info->move_speed;
	if (!info->map_info[(int)(info->loc.x)] \
						[(int)(info->loc.y - info->dir.y * info->move_speed)])
		info->loc.y -= info->dir.y * info->move_speed;
}

void	move_right(t_info *info)
{
	double	perp_dir_x;
	double	perp_dir_y;

	perp_dir_x = info->dir.y;
	perp_dir_y = -info->dir.x;
	if (!info->map_info[(int)(info->loc.x + perp_dir_x * info->move_speed)] \
						[(int)(info->loc.y)])
		info->loc.x += perp_dir_x * info->move_speed;
	if (!info->map_info[(int)(info->loc.x)] \
						[(int)(info->loc.y + perp_dir_y * info->move_speed)])
		info->loc.y += perp_dir_y * info->move_speed;
}

void	move_left(t_info *info)
{
	double	perp_dir_x;
	double	perp_dir_y;

	perp_dir_x = info->dir.y;
	perp_dir_y = -info->dir.x;
	if (!info->map_info[(int)(info->loc.x - perp_dir_x * info->move_speed)] \
						[(int)(info->loc.y)])
		info->loc.x -= perp_dir_x * info->move_speed;
	if (!info->map_info[(int)(info->loc.x)] \
						[(int)(info->loc.y - perp_dir_y * info->move_speed)])
		info->loc.y -= perp_dir_y * info->move_speed;
}
