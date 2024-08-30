/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:46:51 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/03 16:09:23 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	if (dest == src || num == 0)
		return (dest);
	temp1 = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	if (temp1 > temp2)
	{
		i = num;
		while (i--)
			*(temp1 + i) = *(temp2 + i);
	}
	else
	{
		i = 0;
		while (i < num)
		{
			temp1[i] = temp2[i];
			i++;
		}
	}
	return (temp1);
}
