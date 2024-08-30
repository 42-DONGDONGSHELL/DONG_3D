/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:36:52 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/09 19:59:20 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_length_strdup(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != 0)
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		size;
	int		idx;
	char	*rtn;

	size = get_length_strdup(s);
	rtn = malloc(sizeof(char) * (size + 1));
	if (!rtn)
		return (0);
	idx = 0;
	while (s[idx])
	{
		rtn[idx] = s[idx];
		idx++;
	}
	rtn[idx] = 0;
	return (rtn);
}
