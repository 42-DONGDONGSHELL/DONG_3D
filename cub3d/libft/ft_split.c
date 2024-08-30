/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:42:53 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/10 19:57:27 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **ss)
{
	size_t	i;

	i = 0;
	while (ss[i])
	{
		free(ss[i]);
		i++;
	}
	free(ss);
	return (0);
}

size_t	ft_word_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	size_t	flag;

	i = 0;
	cnt = 0;
	flag = 0;
	while (s[i])
	{
		if (flag && s[i] == c)
		{
			flag = 0;
			cnt++;
		}
		else if (s[i] != c)
			flag = 1;
		i++;
	}
	if (flag)
		cnt++;
	return (cnt);
}

static char	*get_word(char const *s, size_t *j, char c)
{
	size_t	i;
	size_t	k;
	char	*word;

	while (s[*j] && s[*j] == c)
		(*j)++;
	i = *j;
	while (s[*j] && s[*j] != c)
		(*j)++;
	word = (char *)malloc(sizeof(char) * (*j - i + 1));
	if (!word)
		return (0);
	k = -1;
	while (++k < (*j - i))
		word[k] = s[i + k];
	word[k] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_num;
	char	**res;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	word_num = ft_word_cnt(s, c);
	res = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (i < word_num)
	{
		res[i] = get_word(s, &j, c);
		if (!res[i])
			return (free_all(res));
		i++;
	}
	res[i] = 0;
	return (res);
}
