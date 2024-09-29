#ifndef CUB3D_H
# define CUB3D_H

#	include "../minilibx/mlx.h"
#	include "../libft/libft.h"

#	include <stdio.h> // printf, perror
#	include <unistd.h> // read, write
#	include <stdlib.h> // malloc, free, exit
#	include <string.h> // strerror
#	include <fcntl.h> // open, close
#	include <sys/time.h> // gettimeofday
#	include <math.h> // all functions of the math library

#define WIDTH 640
#define HEIGHT 480

typedef struct	s_xy
{
 	double	x; //position x du sprite
	double	y; //position y du sprite
}	t_xy;

typedef struct s_tex
{
	char *n_p; // texture 정보
	char *s_p;
	char *w_p;
	char *e_p;
	int *f_rgb;	// 바닥 색상
	int *c_rgb;	// 천장 색상
}	t_tex;

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_info
{
	t_xy loc;
	t_xy plane;
	t_xy dir;
	int **map_info;
	int map_height;
	int map_width;
	t_tex texture;
	int		**textures;
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
	int		buf[HEIGHT][WIDTH];
	double	moveSpeed;
	double	rotSpeed;
}	t_info;

int	render(t_info *info);

#	include "get_next_line.h"
#	include "read_file.h"
#	include "util.h"
#	include "validation.h"

#endif
