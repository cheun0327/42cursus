/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:15:57 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/29 21:12:02 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nlen(long long n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void		do_itoa(long long temp, char *str, size_t len)
{
	str[len] = 0;
	if (temp == 0)
	{
		str[--len] = '0';
		return ;
	}
	while (temp > 0)
	{
		str[--len] = (temp % 10) + '0';
		temp /= 10;
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long long	temp;

	len = nlen(n);
	temp = n;
	if (n < 0)
	{
		temp *= -1;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n < 0)
		str[0] = '-';
	do_itoa(temp, str, len);
	return (str);
}
