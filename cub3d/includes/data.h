#ifndef DATA_H
# define DATA_H

# include "cub3d.h"

typedef struct s_xy
{
	double	x;
	double	y;
}	t_xy;

typedef struct s_tex
{
	char			*n_p;
	char			*s_p;
	char			*w_p;
	char			*e_p;
	unsigned int	f_hash;
	unsigned int	c_hash;
}	t_tex;

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_w;
	int		img_h;
}				t_img;

typedef struct s_info
{
	t_xy	loc;
	t_xy	plane;
	t_xy	dir;
	int		**map_info;
	int		map_height;
	int		map_width;
	t_tex	texture;
	int		**tex;
	void	*mlx;
	void	*win;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_right;
	int		key_left;
	int		key_esc;
	t_img	img;
	int		**buf;
	double	move_speed;
	double	rot_speed;
}	t_info;

#endif
