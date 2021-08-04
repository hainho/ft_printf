/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:01:44 by iha               #+#    #+#             */
/*   Updated: 2021/08/04 18:01:46 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);

int		ft_formc(int c);
int		ft_forms(char *s);

int		ft_formx(unsigned int x);
int		ft_formux(unsigned int x);
int		ft_formp(unsigned long long p);

int		ft_formd(int d);
int		ft_formi(int i);
int		ft_formu(unsigned int u);

char	*itoh(unsigned long long i, bool is_ptr, bool is_upper);
char	*ft_uitoa(unsigned int n);

#endif
