/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:51:29 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/21 08:48:54 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

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

/* Print stacks a & b. */
void	print_stacks(t_stacks *sts)
{
	int	i;

	i = -1;
	while (++i < sts->initial_size)
	{
		ft_printf("a[%d] = ", i);
		if (sts->a->st[i] == LONG_MAX)
			ft_printf("   ");
		else
			ft_printf("%d  ", sts->a->st[i]);
		ft_printf("b[%d] = ", i);
		if (sts->b->st[i] == LONG_MAX)
			ft_printf(" \n");
		else
			ft_printf("%d\n", sts->b->st[i]);
	}
}

int	is_dupl(long n, long *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(long *arr, int size)
{
	int	i;

	if (size == 1)
		return (1);
	i = 0;
	while (++i < size)
		if (arr[i - 1] > arr[i])
			return (0);
	return (1);
}
