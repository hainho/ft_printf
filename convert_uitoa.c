/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uitoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:02:58 by iha               #+#    #+#             */
/*   Updated: 2021/08/04 18:07:16 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uitoasize(unsigned int n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_rec_uitoa(long long n, char *dst)
{
	if (n == 0)
		return (dst);
	if (n > 0)
	{
		dst = ft_rec_uitoa(n / 10, dst);
		*dst = n % 10 + '0';
	}
	return (dst + 1);
}

char	*ft_uitoa(unsigned int n)
{
	char			*dst;
	char			*temp;
	int				size;
	long long		m;

	m = n;
	size = ft_uitoasize(n);
	if (n < 0)
		m *= -1;
	dst = malloc(size + 1);
	if (dst == NULL)
		return (NULL);
	temp = dst;
	if (n < 0)
		*dst++ = '-';
	if (n == 0)
		*dst++ = '0';
	dst = ft_rec_uitoa(m, dst);
	*dst = 0;
	return (temp);
}
