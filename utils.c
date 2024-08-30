/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:43:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/30 11:39:24 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Return absolute value of long number. */
long	ps_abs(long num)
{
	if (num < 0)
		return (-num);
	return (num);
}

/* Convert string to integer. Uses long in order to catch int overflow. Returns
 * LONG_MAX if string contains not number chars, number represented by is too
 * big or too small.*/
long	ps_atol(const char *s)
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

/* Exit func in case early malloc fails. */
void	exit_error_malloc(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(ENOMEM);
}

/* Exit func in case malloc fails but there might be things allocated in stacks
 * struct. */
void	exit_error_malloc_free_stacks(t_stacks **sts)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks(sts);
	exit(ENOMEM);
}

/* Exit func in case there were invalid args. */
void	exit_error_arg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EINVAL);
}
