/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:59:23 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/24 19:59:24 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
int					ft_isdigit(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2, int free_target);
int					ft_putchar(char c);
int					ft_putstr(char *s);

#endif
