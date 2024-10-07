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

void	calc(t_info *info);

int		load_texture(t_info *info);

#endif
