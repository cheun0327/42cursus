/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:23:41 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/14 12:26:10 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int			ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
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
	print_t_info(info);
}

int			print_char(int arg, t_info *info)
{
	printf("--%d\n", arg);
	print_t_info(info);
	return (arg);
}

int			print_str(char * arg, t_info * info)
{
	printf("--%s\n", arg);
	print_t_info(info);
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
	print_t_info(info);
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
			ret += ft_putchar_fd(format[i++], 1);
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
	char c = 'a';
	
	ft_printf("[%-03.*c]", 5, c);
	ft_printf("%s", s);
	ft_printf("%d", 10);
	ft_printf("%u", 1234);
	ft_printf("%x")
	
	return 0;
}