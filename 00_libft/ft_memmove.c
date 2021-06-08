/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:41:59 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/26 14:29:15 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	return (dst);
}
