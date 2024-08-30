#include "get_next_line.h"

char	*ft_get_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	read_bytes = 1;
	while (!gl_strchr(line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line = gl_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

int	get_line_length(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		return (i + 1);
	return (i);
}

char	*ft_get_next_line(char *line)
{
	int		length;
	int		i;
	char	*str;

	if (!line || !line[0])
		return (NULL);
	length = get_line_length(line);
	str = (char *)malloc(length + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < length && line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (gl_strlen(line) - i + 1));
	if (!str)
	{
		free(line);
		return (NULL);
	}
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char			*line;
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_get_line(fd, line);
	if (!line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	next_line = ft_get_next_line(line);
	if (next_line == NULL)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = new_line(line);
	return (next_line);
}
