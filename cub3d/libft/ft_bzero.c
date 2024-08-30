/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:45:01 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/03 15:57:34 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t num)
{
	unsigned char	*dest;
	unsigned char	src;
	size_t			i;

	dest = s;
	src = 0;
	i = 0;
	while (i < num)
		dest[i++] = src;
	return ;
}
