/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:49:16 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/11 17:45:42 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
//#include "./libft/libft.h"

#define TYPES "csdiuxX%"

typedef struct  s_info
{
    int         minus;
    int         zero;
    int         width;
    int         prec;
    char        type;
}               t_info;

int             ft_printf(const char *format, ...);

#endif