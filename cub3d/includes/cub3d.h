#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/time.h>
# include <math.h>

# include "data.h"
# include "get_next_line.h"
# include "read_file.h"
# include "util.h"
# include "validation.h"

# define WIDTH 900
# define HEIGHT 600

int	render(t_info *info);

#endif
