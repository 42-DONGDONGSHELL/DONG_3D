#include "../../includes/render.h"

void	draw_floor_ceiling(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->buf[y][x] = info->texture.f_hash;
			info->buf[HEIGHT - y - 1][x] = info->texture.c_hash;
			x++;
		}
		y++;
	}
}

void	initialize_ray(t_info *info, int x, t_dda_vars *dda)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	dda->ray_dir_x = info->dir.x + info->plane.x * camera_x;
	dda->ray_dir_y = info->dir.y + info->plane.y * camera_x;
}

void	setup_dda(t_info *info, t_dda_vars *dda)
{
	dda->map_x = (int)info->loc.x;
	dda->map_y = (int)info->loc.y;
	dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (info->loc.x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - info->loc.x) * dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (info->loc.y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - info->loc.y) * dda->delta_dist_y;
	}
}

int	perform_dda(t_info *info, t_dda_vars *dda)
{
	int	hit;
	int	side;

	hit = 0;
	side = 0;
	while (hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			side = 1;
		}
		if (info->map_info[dda->map_x][dda->map_y] > 0)
			hit = 1;
	}
	return (side);
}

double	calculate_perp_wall_dist(t_info *info, t_dda_vars *dda, int side)
{
	if (side == 0)
		return ((dda->map_x - info->loc.x + \
				(1 - dda->step_x) / 2) / dda->ray_dir_x);
	else
		return ((dda->map_y - info->loc.y + \
				(1 - dda->step_y) / 2) / dda->ray_dir_y);
}
