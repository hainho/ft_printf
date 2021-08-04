/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:00:30 by iha               #+#    #+#             */
/*   Updated: 2021/08/04 18:00:31 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formx(unsigned int x)
{
	char	*format_str;
	int		len;

	format_str = itoh(x, false, false);
	len = ft_strlen(format_str);
	ft_putstr_fd(format_str, 1);
	free(format_str);
	return (len);
}

int	ft_formux(unsigned int x)
{
	char	*format_str;
	int		len;

	format_str = itoh(x, false, true);
	len = ft_strlen(format_str);
	ft_putstr_fd(format_str, 1);
	free(format_str);
	return (len);
}

int	ft_formp(unsigned long long p)
{
	char	*format_str;
	int		len;

	format_str = itoh(p, true, false);
	len = ft_strlen(format_str);
	ft_putstr_fd(format_str, 1);
	free(format_str);
	return (len);
}
