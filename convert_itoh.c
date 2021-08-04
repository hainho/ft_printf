/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_itoh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:56:08 by iha               #+#    #+#             */
/*   Updated: 2021/08/04 17:56:12 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_size(unsigned long long h)
{
	int	s;

	s = 0;
	if (h == 0)
		return (1);
	while (h)
	{
		h /= 16;
		s++;
	}
	return (s);
}

static char	ntoh(int n, bool is_upper)
{
	if (n < 10)
		return ('0' + n);
	else if (is_upper)
		return ('A' + n - 10);
	else
		return ('a' + n - 10);
}

static char	*ntoh_all(char *cur_hex, unsigned long long i, bool is_upper)
{
	int	temp;

	if (i == 0)
	{
		*cur_hex = '0';
		return (cur_hex);
	}
	temp = i % 16;
	if (i > 0)
	{
		cur_hex = ntoh_all(cur_hex, i / 16, is_upper);
		*cur_hex = ntoh(temp, is_upper);
		return (cur_hex + 1);
	}
	return (cur_hex);
}

static char	*htop(char *hex_str)
{
	char	*join_str;
	char	*ptr_str;

	ptr_str = malloc(sizeof(char) * (3));
	if (ptr_str == NULL)
		return (NULL);
	ptr_str[0] = '0';
	ptr_str[1] = 'x';
	ptr_str[2] = '\0';
	join_str = ft_strjoin(ptr_str, hex_str);
	if (join_str == NULL)
		return (NULL);
	free(ptr_str);
	free(hex_str);
	return (join_str);
}

char	*itoh(unsigned long long i, bool is_ptr, bool is_upper)
{
	char	*hex_str;
	int		s;

	s = hex_size(i);
	hex_str = (char *)malloc(sizeof(char) * (s + 1));
	hex_str[s] = '\0';
	ntoh_all(hex_str, i, is_upper);
	if (is_ptr)
		hex_str = htop(hex_str);
	return (hex_str);
}
