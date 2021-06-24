/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:17:57 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/24 20:17:59 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*new_str;

	len = 0;
	while (str[len])
		len++;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new_str))
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
