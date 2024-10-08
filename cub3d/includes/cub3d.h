/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:21:55 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/08 20:21:56 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define WIDTH 1200
# define HEIGHT 800

int	render(t_info *info);

#endif
