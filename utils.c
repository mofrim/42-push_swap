/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:43:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 09:01:59 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ps_abs(long num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	is_in(long *arr, int val, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (arr[i] == val)
			return (1);
	return (0);
}

void	exit_error_malloc(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(ENOMEM);
}

void	exit_error_arg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EINVAL);
}
