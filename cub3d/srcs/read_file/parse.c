#include "../../includes/cub3d.h"

void	parse_rgb(char *buf, int *rgb)
{
	char	**colors;
	int		i;
	int		count;

	colors = ft_split(buf, ',');
	if (!colors)
		exit(1); // todo : error msg 여부.
	count = 0;
	while (colors[count] != NULL)
		count++;
	if (count != 3)
		error_exit("Error\nInvalid RGB format");
	i = -1;
	while (++i < 3)
	{
		if (!isdigit_str(colors[i]))
			error_exit("Error\nInvalid RGB value");
		rgb[i] = ft_atoi(colors[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			error_exit("Error\nRGB value out of range (0-255)");
	}
	i = -1;
	while (colors[++i])
		free(colors[i]);
	free(colors);
}

void	init_identifier(int idx, char *buf, t_info *info)
{
	strip_newline(buf);
	if (idx == 0)
		info->texture.e_p = ft_strdup(buf + 3);
	else if (idx == 1)
		info->texture.w_p = ft_strdup(buf + 3);
	else if (idx == 2)
		info->texture.s_p = ft_strdup(buf + 3);
	else if (idx == 3)
		info->texture.n_p = ft_strdup(buf + 3);
	else if (idx == 4)
		parse_rgb(buf + 2, info->texture.c_rgb);
	else if (idx == 5)
		parse_rgb(buf + 2, info->texture.f_rgb);
}
