#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17
# define W 13
# define A 0
# define S 1
# define D 2
# define L 123
# define R 124
# define ESC 53
# define WALL_MARGIN 0.01

typedef struct s_dda_vars {
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	ray_dir_x;
	double	ray_dir_y;
}	t_dda_vars;

typedef struct s_wall_vars {
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	int		tex_x;
}	t_wall_vars;

void	move_forward(t_info *info);
void	move_backward(t_info *info);
void	move_right(t_info *info);
void	move_left(t_info *info);
void	rotate_right(t_info *info);
void	rotate_left(t_info *info);

int		destroy(t_info *info);
int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);
void	key_update(t_info *info);

void	draw_floor_ceiling(t_info *info);
void	initialize_ray(t_info *info, int x, t_dda_vars *dda);
void	setup_dda(t_info *info, t_dda_vars *dda);
int		perform_dda(t_info *info, t_dda_vars *dda);
double	calculate_perp_wall_dist(t_info *info, t_dda_vars *dda, int side);

void	ray_cast(t_info *info);

int		load_texture(t_info *info);

#endif
