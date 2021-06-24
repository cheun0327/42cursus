/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:18:34 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/24 20:18:35 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;
	size_t	b_len;
	size_t	size;

	if (*little == '\0')
		return ((char *)big);
	l_len = ft_strlen(little);
	b_len = ft_strlen(big);
	if (b_len < l_len || len < l_len)
		return (0);
	size = b_len > len ? len : b_len;
	while (size-- >= l_len)
	{
		if (ft_memcmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
