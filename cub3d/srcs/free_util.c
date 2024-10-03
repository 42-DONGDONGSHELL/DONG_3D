#include "../includes/cub3d.h"

void	free_textures_paths(t_info *info)
{
	safe_free((void **)&info->texture.n_p);
	safe_free((void **)&info->texture.s_p);
	safe_free((void **)&info->texture.w_p);
	safe_free((void **)&info->texture.e_p);
}

void	free_rgb_arrays(t_info *info)
{
	safe_free((void **)&info->texture.c_rgb);
	safe_free((void **)&info->texture.f_rgb);
}

void	free_map_info(t_info *info)
{
	if (info->map_info)
		free_2d_array((void **)info->map_info, info->map_height);
}

void	free_textures(t_info *info)
{
	if (info->textures)
	{
		for (int i = 0; i < 8; i++)
			safe_free((void **)&info->textures[i]);
		safe_free((void **)&info->textures);
	}
}

void	free_all_resources(t_info *info)
{
	free_textures_paths(info);
	free_rgb_arrays(info);
	free_map_info(info);
	free_textures(info);
}