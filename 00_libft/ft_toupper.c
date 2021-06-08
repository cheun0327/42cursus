/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:29:00 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/24 22:11:00 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

int		ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 'a' + 'A');
	return (c);
}
