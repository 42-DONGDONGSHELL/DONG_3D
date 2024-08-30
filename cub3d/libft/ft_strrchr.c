/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:53:37 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/02 21:02:14 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	size_t	i;
	char	*ret;

	ch = c;
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == ch)
			ret = ((char *)(str + i));
		i++;
	}
	if (ret)
		return (ret);
	if (ch == 0)
		return ((char *)(str + i));
	return (0);
}
