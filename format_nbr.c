/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:01:13 by iha               #+#    #+#             */
/*   Updated: 2021/08/04 18:01:14 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formd(int d)
{
	char	*format_str;
	int		len;

	format_str = ft_itoa(d);
	len = ft_strlen(format_str);
	ft_putstr_fd(format_str, 1);
	free(format_str);
	return (len);
}

int	ft_formi(int i)
{
	char	*format_str;
	int		len;

	format_str = ft_itoa(i);
	len = ft_strlen(format_str);
	ft_putstr_fd(format_str, 1);
	free(format_str);
	return (len);
}

int	ft_formu(unsigned int u)
{
	char	*format_str;
	int		len;

	format_str = ft_uitoa(u);
	len = ft_strlen(format_str);
	ft_putstr_fd(format_str, 1);
	free(format_str);
	return (len);
}
