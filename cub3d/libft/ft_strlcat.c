/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:08:38 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/03 16:01:58 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_length(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_idx;
	size_t	s_idx;
	size_t	dest_len;

	dest_len = get_length(dest);
	s_idx = 0;
	d_idx = dest_len;
	while (d_idx + 1 < size && src[s_idx] != '\0')
	{
		dest[d_idx] = src[s_idx];
		d_idx++;
		s_idx++;
	}
	if (size > 0)
		dest[d_idx] = '\0';
	if (dest_len > size)
	{
		return (size + get_length(src));
	}
	return (dest_len + get_length(src));
}
