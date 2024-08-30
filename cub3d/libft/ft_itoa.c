/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:17:10 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/08 21:13:16 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_converted_len(int n)
{
	int	rtn;

	if (n == 0)
		return (1);
	rtn = 0;
	if (n < 0)
	{
		rtn++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		rtn++;
	}
	return (rtn);
}

char	*special_rtn(int n, char *s)
{
	int	len;

	len = 11;
	s[0] = '-';
	while (len-- > 1)
	{
		s[len] = (n % 10) * (-1) + '0';
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = get_converted_len(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	res[len] = 0;
	if (n == -2147483648)
		return (special_rtn(n, res));
	i = 0;
	if (n < 0)
	{
		res[i++] = '-';
		n *= -1;
	}
	while (len-- > i)
	{
		res[len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
