/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:46:59 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/02 21:00:36 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*dest;
	unsigned char	src;
	size_t			i;

	dest = ptr;
	src = value;
	i = 0;
	while (i < num)
		dest[i++] = src;
	return (dest);
}
