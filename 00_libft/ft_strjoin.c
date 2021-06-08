/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:51:13 by chaeekim          #+#    #+#             */
/*   Updated: 2020/12/26 20:14:39 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (*s1 != 0)
		ptr[i++] = *s1++;
	while (*s2 != 0)
		ptr[i++] = *s2++;
	ptr[i] = 0;
	return (ptr);
}
