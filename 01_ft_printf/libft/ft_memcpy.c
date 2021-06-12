/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:23:59 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/24 22:07:33 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned char		*dst;
	unsigned const char *str;

	if (s1 == 0 && s2 == 0)
		return (0);
	i = 0;
	dst = (unsigned char *)s1;
	str = (unsigned char *)s2;
	while (i < n)
	{
		*(dst + i) = *(str + i);
		i++;
	}
	return (dst);
}
