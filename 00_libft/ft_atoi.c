/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:31:07 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/29 21:41:45 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
			|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int		check_over_range(unsigned long long sum, int sign)
{
	if (sum > LLONG_MAX - 1 && sign == -1)
		return (0);
	if (sum > LLONG_MAX && sign == 1)
		return (-1);
	return (sum * sign);
}

int				ft_atoi(const char *str)
{
	long long	nbr;
	int			sign;
	size_t		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] != 0 && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] != 0) && ('0' <= str[i]) && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (check_over_range(nbr, sign));
}
