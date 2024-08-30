/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongclee <dongclee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:31:44 by dongclee          #+#    #+#             */
/*   Updated: 2023/11/09 19:50:26 by dongclee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_len(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	get_pow(int n)
{
	int	i;
	int	ret;

	i = 1;
	ret = 1;
	while (i < n)
	{
		ret *= 10;
		i++;
	}
	return (ret);
}

void	ft_putnbr_fd2(int n, int pow, int fd)
{
	char	c;
	int		num;

	while (pow > 0)
	{
		num = n / pow;
		c = num + '0';
		write(fd, &c, 1);
		n %= pow;
		pow /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	ft_putnbr_fd2(n, get_pow(check_len(n)), fd);
}
