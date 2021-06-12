/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:57:18 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/26 19:17:52 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s1len;
	size_t	s2len;
	size_t	size;

	if (*s2 == 0)
		return ((char *)s1);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len < s2len || len < s2len)
		return (0);
	size = s1len > s2len ? len : s1len;
	while (size-- >= s2len)
	{
		if (ft_memcmp(s1, s2, s2len) == 0)
			return ((char *)s1);
		s1++;
	}
	return (0);
}
