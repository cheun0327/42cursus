/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:17:40 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/24 12:02:28 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t i;
	size_t destlen;
	size_t srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (dstsize <= destlen)
		return (dstsize + srclen);
	while (src[i] && destlen + i + 1 < dstsize)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (destlen + srclen);
}
