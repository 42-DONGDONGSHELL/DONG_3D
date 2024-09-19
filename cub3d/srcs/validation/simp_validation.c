#include "../../includes/cub3d.h"

int	isdigit_str(char *str)
{
	int i;

	str = trim_spaces(str);
	printf("%s.\n", str);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_arg(int argc, char **argv)
{
	if (argc != 2)
		error_exit("ERROR\nCMD Format :: \".cub3d [FILE_PATH]\"");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		error_exit("ERROR!\nNot a .cub file");
	return (0);
}
