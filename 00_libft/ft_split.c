/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:44:57 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/29 21:24:12 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_count(const char *s, char c)
{
	size_t		cnt;
	size_t		i;
	int			flag;

	i = 0;
	cnt = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
			flag = 0;
		else if (!flag && s[i] != c && s[i])
		{
			cnt++;
			flag = 1;
		}
		i++;
	}
	return (cnt);
}

static void		copy(char *dst, char const *src, size_t start, size_t end)
{
	size_t		i;

	i = 0;
	while (start < end)
		dst[i++] = src[start++];
	dst[i] = 0;
}

static void		split(char const *s, char c, char **str)
{
	size_t		start;
	size_t		i;
	size_t		j;

	start = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			if (!(str[j] = (char *)malloc(sizeof(char) * (i - start + 1))))
			{
				free(str);
				return ;
			}
			copy(str[j++], s, start, i);
		}
		else if (s[i])
			i++;
	}
}

char			**ft_split(char const *s, char c)
{
	char		**str;
	size_t		n;

	if (s == 0)
		return (NULL);
	n = get_count(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	str[n] = 0;
	if (n == 0)
		return (str);
	split(s, c, str);
	return (str);
}
