#include "../includes/cub3d.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit(1);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void	safe_free(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_2d_array(void **array, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(array[i]);
	free(array);
}

void	strip_newline(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

void	error_exit(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

char	*trim_spaces(char *str)
{
	int	start;
	int	end;

	start = 0;
	while (str[start] && (str[start] == ' ' || str[start] == '\t'))
		start++;
	end = ft_strlen(str) - 1;
	while (end > start && (str[end] == ' ' || str[end] == '\t'))
		end--;
	str[end + 1] = '\0';
	return (str + start);
}

char	*trim_rspaces(char *str)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (end >= start && (str[end] == ' ' || str[end] == '\t'))
		end--;
	str[end + 1] = '\0';
	return (str + start);
}
