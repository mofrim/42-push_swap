/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:51:29 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/20 13:05:56 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

/* Convert string to integer. Uses long in order to catch int overflow. Returns
 * LONG_MAX if string contains not number chars, number represented by is too
 * big or too small.*/
long	ft_atol(const char *s)
{
	long	num;
	long	sgn;

	num = 0;
	sgn = 1;
	if (*s == '-')
	{
		sgn = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		num = num * 10 + *s++ - '0';
		if (sgn > 0 && num > INT_MAX)
			return (LONG_MAX);
		if (sgn < 0 && num > (-1) * (long)INT_MIN)
			return (LONG_MAX);
	}
	if (*s != 0 && !ft_isdigit(*s))
		return (LONG_MAX);
	return (num * sgn);
}
