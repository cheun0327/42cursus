/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:18:39 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/24 20:18:40 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	char		*last;
	char		find;
	size_t		i;

	last = (char *)s;
	find = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == find)
			return (last + i);
		i--;
	}
	if (last[i] == find)
		return (last);
	return (0);
}
