/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:23:41 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/19 23:55:07 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int			ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2, int free_num)
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
	if (free_num == 1 || free_num == 3)
		free (s1);
	if (free_num == 2 || free_num == 3)
		free (s2);
	return (ptr);
}

int			ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}




void		init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 0;
}

void		print_t_info(t_info *info)
{
	printf("\nminus : %d\n", info->minus);
	printf("zero : %d\n", info->zero);
	printf("width : %d\n", info->width);
	printf("prec : %d\n", info->prec);
	printf("type : %c\n", info->type);
}

//TODO width and prec process 과정 파악하기 우선순위
void		check_width_and_prec(va_list ap, char *format, t_info *info, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + format[i] - 48;
		else
			info->prec = info->prec * 10 + format[i] - 48;
	}
	else if (format[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}

/*
** Character, %
*/

int			put_char_width(int width, int len, int zero)
{
	int		ret;

	ret = 0;
	while (len < width)
	{
		//char은 해당 없지만, %는 '0'flag 가능
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		ret++;
	}
	return (ret);
}

int			print_char(int c, t_info *info)
{
	int		ret;

	ret = 0;
	//%타입 이거나 '-'왼쪽 정렬 있으면 zero padding 무시
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	//왼쪽 정렬 있으면 문자를 먼저 출력해줌
	if (info->minus == 1)
		ret += ft_putchar(c);
	//width계산해서 출력
	ret += put_char_width(info->width, 1, info->zero);
	//왼쪽 정렬 아니었으면 width다음으로 문자 출력
	if (info->minus == 0)
		ret += ft_putchar(c);
	return (ret);
}

/*
** String
*/

char			*set_buf(char *str, int prec, int len)
{
	int			i;
	int			end;
	char		*buf;
	
	end = prec < len ? prec : len;
	if (!(buf = (char *)malloc(sizeof(char) * end + 1)))
		return (NULL);
	i = 0;
	while (i < end)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int			put_str_width(char **buf, t_info *info)
{
	char	**width;
	int		i;
	
	//TODO int로 형변환 안하면 어떻게 됨??
	if (info->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	width = (char *)malloc(sizeof(char) * (info->width - ft_strlen(*buf) + 1));
	i = 0;
	while ((size_t)i < info->width - ft_strlen(*buf))
	{
		width[i] = (info->zero == 1) ? '0' : ' ';
		i++;
	}
	width[i] = '\0';
	if (info->minus == 0)
		*buf = ft_strjoin(width, *buf, 3);
	else
		*buf = ft_strjoin(*buf, width, 3);
	//TODO return ((int)ft_strlen(*buf));
	return (info->width);
	
}

int			print_str(char * str, t_info * info)
{
	int		ret;
	char	*buf;
	
	ret = 0;
	// TODO NULL인 경우 어떻게 처리하는지 확인
	if (str == NULL)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		info->prec = ft_strlen(str);
	buf = set_buf(str, info->prec, ft_strlen(str));
	ret = put_str_width(&buf, info);
	ft_putstr(buf);
	free(buf);
	return (0);
}

int			print_num(unsigned long long num, t_info * info)
{
	if (info->type == 'd' || info->type == 'i')
		printf("%llu", num);
	return (0);
}

int			print_type(va_list ap, t_info *info)
{
	int		ret;
	char	type;

	ret = 0;
	type = info->type;
	print_t_info(info);
	if (type == 'c')
		ret = print_char(va_arg(ap, int), info);	//ascii값으로 읽는다 -> int
	else if (type == '%')
		ret = print_char('%', info);
	
	else if (type == 's')
		ret = print_str(va_arg(ap, char *), info);
	else if (type == 'd' || type == 'i')
		ret = print_num(va_arg(ap, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		ret = print_num(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		ret = print_num(va_arg(ap, unsigned long long), info);
	return (ret);
}

void		check_info(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '.')			//prec은 -값도 있고, 숫자가 없으면 디폴트로 0이 되기때문에
		info->prec = 0;					
	else if (ft_isdigit(format[i]) || format[i] == '*')
		check_width_and_prec(ap, format, info, i);
}

int			parse_format(va_list ap, char *format)
{
	int				i;
	int 			ret;
	t_info			 *info;

	i = 0;
	ret = 0;
	if (!(info = malloc(sizeof(t_info) * 1)))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ret += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_info(info);
			while (format[++i] != '\0' && !(ft_strchr(TYPES, format[i])))
				check_info(ap, format, info, i);
			info->type = format[i++];
			if ((info->minus == 1 || info->prec >- 1) && info->type != '%')
				info->zero = 0;
			ret += print_type(ap, info);
		}
	}
	free(info);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	int				ret;
	va_list			ap;

	va_start(ap, format);
	ret = parse_format(ap, (char *)format);
	va_end(ap);
	return (ret);
}

int			main()
{
	char *s = "Hello";
	// char c = 'a';
	
	// CHAR DONE
	// ft_printf("[%-5.*c]", 5, c);
	// ft_printf("[%-5.*c]", 5, c);
	// ft_printf("[%05%]");
	// ft_printf("[%-05%]");
	// ft_printf("[%-*%]", 5);

	// STRING ING~
	ft_printf("%s", s);
	
	// ft_printf("%d", 10);
	// ft_printf("%u", 1234);
	// ft_printf("%x")
	
	return 0;
}