/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:19:32 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/03 16:11:06 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	find_len;

	find_len = ft_strlen(to_find);
	if (find_len == 0)
		return ((char *)str);
	i = 0;
	while (i < len && str[i])
	{
		k = i;
		j = 0;
		while (i < len && str[i] && to_find[j])
		{
			if (str[i] != to_find[j])
				break ;
			i++;
			j++;
		}
		if (j == find_len)
			return ((char *)&str[k]);
		i = k + 1;
	}
	return (0);
}
