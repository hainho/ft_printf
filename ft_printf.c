/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:01:31 by iha               #+#    #+#             */
/*   Updated: 2021/08/04 18:01:32 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char format, va_list ap)
{
	if (format == 'd')
		return (ft_formd(va_arg(ap, int)));
	if (format == 'i')
		return (ft_formi(va_arg(ap, int)));
	if (format == 'u')
		return (ft_formu(va_arg(ap, unsigned int)));
	if (format == 'x')
		return (ft_formx(va_arg(ap, unsigned int)));
	if (format == 'X')
		return (ft_formux(va_arg(ap, unsigned int)));
	if (format == 'p')
		return (ft_formp(va_arg(ap, unsigned long long)));
	if (format == 'c')
		return (ft_formc(va_arg(ap, int)));
	if (format == 's')
		return (ft_forms(va_arg(ap, char *)));
	if (format == '%')
		return (ft_formc('%'));
	return (-1);
}

static int	ft_read_format(char *cur_str, int count, va_list ap)
{
	char	*target;
	char	*sub_str;
	int		temp;

	while (*cur_str)
	{
		target = ft_strchr(cur_str, '%');
		if (target == NULL)
			target = cur_str + ft_strlen(cur_str);
		sub_str = ft_substr(cur_str, 0, target - cur_str);
		if (sub_str == NULL)
			return (-1);
		ft_putstr_fd(sub_str, 1);
		count += ft_strlen(sub_str);
		free(sub_str);
		if (*target == '\0')
			break ;
		temp = ft_format(*(target + 1), ap);
		if (temp == -1)
			return (-1);
		count += temp;
		cur_str = target + 2;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	char	*cur_str;
	int		count;
	va_list	ap;

	cur_str = (char *)format;
	va_start(ap, format);
	count = 0;
	count = ft_read_format(cur_str, count, ap);
	if (count == -1)
		return (-1);
	return (count);
}
