/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:01:44 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/03 17:02:01 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;
	size_t	ret;

	ret = 0;
	idx = 0;
	while ((s1[idx] || s2[idx]) && ret == 0 && idx < n)
	{
		ret = (unsigned char)s1[idx] - (unsigned char)s2[idx];
		if (ret != 0)
			return (ret);
		idx++;
	}
	return (ret);
}
