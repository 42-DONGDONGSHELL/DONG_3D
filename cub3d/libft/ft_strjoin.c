/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:27:52 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/08 21:04:05 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*rtn;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = (int)ft_strlen(s1);
	s2_len = (int)ft_strlen(s2);
	rtn = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
	if (!rtn)
		return (0);
	rtn[s1_len + s2_len] = 0;
	i = 0;
	while (i < s1_len)
	{
		rtn[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		rtn[i++] = s2[j++];
	return (rtn);
}
