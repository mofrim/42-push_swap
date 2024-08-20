/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:43:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/20 12:02:37 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swp.h"

long	ft_abs(long num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	get_max_indx(t_stack *s)
{
	int	i;
	int	max;
	int	imax;

	if (!s->size)
		return (-1);
	i = 0;
	max = s->st[0];
	imax = 0;
	while (i < s->size)
	{
		if (max < s->st[i])
		{
			max = s->st[i];
			imax = i;
		}
		i++;
	}
	return (imax);
}

void	free_stacks(t_stacks **st)
{
	free((*st)->a->st);
	free((*st)->b->st);
	free((*st)->a);
	free((*st)->b);
	if ((*st)->dsts_b)
		free((*st)->dsts_b);
	if ((*st)->dsts_a)
		free((*st)->dsts_a);
	if ((*st)->targets)
		free((*st)->targets);
	free(*st);
}

void	exit_error_malloc(void)
{
	ft_printf("malloc error!\n");
	exit(ENOMEM);
}
