/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:15:24 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/24 20:15:25 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (!(mem = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}
