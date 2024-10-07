#include "../../includes/render.h"

void	load_image(t_info *info, int *textures, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			textures[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

int	load_texture(t_info *info)
{
	t_img	img;

	if (!(info->textures = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	for (int i = 0; i < 8; i++)
	{
		if (!(info->textures[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH))))
			return (-1);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < TEX_HEIGHT * TEX_WIDTH; j++)
		{
			info->textures[i][j] = 0;
		}
	}
	load_image(info, info->textures[0], info->texture.n_p, &img);
	load_image(info, info->textures[1], info->texture.s_p, &img);
	load_image(info, info->textures[2], info->texture.w_p, &img);
	load_image(info, info->textures[3], info->texture.e_p, &img);
	return (0);
}
