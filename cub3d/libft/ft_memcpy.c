/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:46:44 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/03 16:08:47 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*temp;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (0);
	temp = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < num)
	{
		temp[i] = s[i];
		i++;
	}
	return (dest);
}
