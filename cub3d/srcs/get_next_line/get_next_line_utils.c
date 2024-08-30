#include "get_next_line.h"

size_t	gl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*gl_strjoin(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	size_t	line_len;
	char	*str;

	if (!buff)
		return (NULL);
	line_len = gl_strlen(line);
	str = malloc(sizeof(char) * (line_len + gl_strlen(buff) + 1));
	if (!str)
	{
		free(line);
		return (NULL);
	}
	i = -1;
	while (++i < line_len)
		str[i] = line[i];
	j = 0;
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(line);
	return (str);
}
