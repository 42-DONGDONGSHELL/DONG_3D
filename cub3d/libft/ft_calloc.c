/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:32:43 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/03 16:02:32 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*ptr;
	size_t	n;

	if (size != 0 && cnt > SIZE_MAX / size)
		return (0);
	ptr = 0;
	ptr = malloc(cnt * size);
	if (ptr == 0)
		return (0);
	n = 0;
	while (n < cnt * size)
	{
		*(unsigned char *)(ptr + n) = 0;
		n++;
	}
	return (ptr);
}
