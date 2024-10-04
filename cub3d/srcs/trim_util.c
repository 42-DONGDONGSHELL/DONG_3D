#include "../includes/cub3d.h"

void	trim_edges(int *line, int *start, int *end, int length)
{
	*start = 0;
	*end = length - 1;
	while (line[*start] == 2)
		(*start)++;
	while (line[*end] == 2 && *end > *start)
		(*end)--;
}

void	strip_newline(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
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
