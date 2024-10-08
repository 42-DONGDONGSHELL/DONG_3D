/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:22:41 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:42 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	calculate_wall_drawing(double perp_wall_dist, t_wall_vars *wall)
{
	wall->line_height = (int)(HEIGHT / perp_wall_dist);
	wall->draw_start = -wall->line_height / 2 + HEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + HEIGHT / 2;
	if (wall->draw_end >= HEIGHT)
		wall->draw_end = HEIGHT - 1;
}

void	determine_texture(t_dda_vars *dda, int side, t_wall_vars *wall)
{
	if (side == 0)
	{
		if (dda->ray_dir_x > 0)
			wall->tex_num = 3;
		else
			wall->tex_num = 2;
	}
	else
	{
		if (dda->ray_dir_y > 0)
			wall->tex_num = 1;
		else
			wall->tex_num = 0;
	}
}

void	calc_tex_x(t_info *info, t_dda_vars *dda, int side, t_wall_vars *wall)
{
	double	wall_x;
	double	perp_wall_dist;

	perp_wall_dist = calculate_perp_wall_dist(info, dda, side);
	if (side == 0)
		wall_x = info->loc.y + perp_wall_dist * dda->ray_dir_y;
	else
		wall_x = info->loc.x + perp_wall_dist * dda->ray_dir_x;
	wall_x -= floor(wall_x);
	wall->tex_x = (int)(wall_x * (double)TEX_WIDTH);
	if (side == 0 && dda->ray_dir_x > 0)
		wall->tex_x = TEX_WIDTH - wall->tex_x - 1;
	if (side == 1 && dda->ray_dir_y < 0)
		wall->tex_x = TEX_WIDTH - wall->tex_x - 1;
}

void	draw_wall_stripe(t_info *info, int x, t_wall_vars *wall)
{
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	int		color;

	step = 1.0 * TEX_HEIGHT / wall->line_height;
	tex_pos = (wall->draw_start - HEIGHT / 2 + wall->line_height / 2) * step;
	y = wall->draw_start;
	while (y < wall->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		color = info->tex[wall->tex_num][TEX_HEIGHT * tex_y + wall->tex_x];
		if (wall->tex_num == 1)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
		y++;
	}
}

void	ray_cast(t_info *info)
{
	int			x;
	t_dda_vars	dda;
	t_wall_vars	wall;
	int			side;
	double		perp_wall_dist;

	draw_floor_ceiling(info);
	x = 0;
	while (x < WIDTH)
	{
		initialize_ray(info, x, &dda);
		setup_dda(info, &dda);
		side = perform_dda(info, &dda);
		perp_wall_dist = calculate_perp_wall_dist(info, &dda, side);
		calculate_wall_drawing(perp_wall_dist, &wall);
		determine_texture(&dda, side, &wall);
		calc_tex_x(info, &dda, side, &wall);
		draw_wall_stripe(info, x, &wall);
		x++;
	}
}
