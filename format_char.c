/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:00:56 by iha               #+#    #+#             */
/*   Updated: 2021/08/04 18:00:58 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formc(int c)
{
	char	temp;

	temp = (char)c;
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_forms(char *s)
{
	int	len;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		len = 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		len = ft_strlen(s);
	}
	return (len);
}
