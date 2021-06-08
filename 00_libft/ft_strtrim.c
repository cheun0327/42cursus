/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:16:23 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/29 21:36:45 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set, size_t slen)
{
	size_t		i;

	i = 0;
	while (i < slen && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	ft_end(char const *s1, char const *set, size_t slen)
{
	size_t		i;

	i = 0;
	while (i < slen && ft_strchr(set, s1[slen - i - 1]))
		i++;
	return (slen - i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	slen;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	i = 0;
	slen = ft_strlen(s1);
	start = ft_start(s1, set, slen);
	end = ft_end(s1, set, slen);
	if (start >= end)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
