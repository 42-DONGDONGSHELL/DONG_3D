/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:09:44 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/03 16:03:12 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t cnt)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;
	int				ret;

	temp1 = (unsigned char *)buf1;
	temp2 = (unsigned char *)buf2;
	i = 0;
	ret = 0;
	while (ret == 0 && i < cnt)
	{
		ret = temp1[i] - temp2[i];
		if (ret != 0)
			return (ret);
		i++;
	}
	return (ret);
}
