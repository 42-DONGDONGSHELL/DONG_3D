/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:17:37 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/03 16:46:56 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t cnt)
{
	unsigned char	ch;

	ch = c;
	while (cnt > 0)
	{
		if (*(unsigned char *)buf == ch)
			return ((void *)buf);
		buf++;
		cnt--;
	}
	return (0);
}
