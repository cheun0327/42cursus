/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 11:39:17 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/28 14:06:47 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t		srclen;
	size_t		i;

	srclen = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[srclen] != 0)
		srclen++;
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (srclen);
}
