/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:08:10 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/09 19:24:50 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*f_str;

	if (s == 0 || f == 0)
		return (0);
	f_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!f_str)
		return (0);
	i = 0;
	while (s[i])
	{
		f_str[i] = f(i, s[i]);
		i++;
	}
	f_str[i] = 0;
	return (f_str);
}
