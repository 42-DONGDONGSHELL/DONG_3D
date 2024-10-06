#include "../../includes/cub3d.h"

unsigned int	rgb_to_hash(int rgb[3])
{
	unsigned int	hash;

	hash = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (hash);
}

int	*parse_and_validate_rgb(char **colors)
{
	int	*rgb;
	int	i;

	rgb = safe_malloc(sizeof(int) * 3);
	i = 0;
	while (i < 3)
	{
		if (!isdigit_str(colors[i]))
			error_exit("Error\nInvalid RGB value");
		rgb[i] = ft_atoi(colors[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			error_exit("Error\nRGB value out of range (0-255)");
		i++;
	}
	return (rgb);
}

void	parse_rgb(char *buf, unsigned int *hash)
{
	char	**colors;
	int		i;
	int		count;
	int		*rgb;

	colors = ft_split(buf, ',');
	if (!colors)
		exit(1);
	count = 0;
	while (colors[count] != NULL)
		count++;
	if (count != 3)
		error_exit("Error\nInvalid RGB format");
	rgb = parse_and_validate_rgb(colors);
	*hash = rgb_to_hash(rgb);
	i = -1;
	while (colors[++i])
		free(colors[i]);
	free(colors);
	free(rgb);
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
		parse_rgb(buf + 2, &(info->texture.c_hash));
	else if (idx == 5)
		parse_rgb(buf + 2, &(info->texture.f_hash));
}
