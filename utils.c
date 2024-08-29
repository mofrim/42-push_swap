/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:43:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/29 18:27:25 by fmaurer          ###   ########.fr       */
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
