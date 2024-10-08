/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:22:45 by dongclee          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:46 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	load_image(t_info *info, int *tex, char *path, t_img *img)
{
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_w, &img->img_h);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
				&img->size_l, &img->endian);
	y = 0;
	while (y < img->img_h)
	{
		x = 0;
		while (x < img->img_w)
		{
			tex[img->img_w * y + x] = \
			img->data[img->img_w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

int	load_texture(t_info *info)
{
	t_img	img;
	int		i;
	int		j;

	info->tex = (int **)safe_malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		info->tex[i] = \
			(int *)safe_malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH));
		j = 0;
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			info->tex[i][j] = 0;
			j++;
		}
		i++;
	}
	load_image(info, info->tex[0], info->texture.n_p, &img);
	load_image(info, info->tex[1], info->texture.s_p, &img);
	load_image(info, info->tex[2], info->texture.w_p, &img);
	load_image(info, info->tex[3], info->texture.e_p, &img);
	return (0);
}
