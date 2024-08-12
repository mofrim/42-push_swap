/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:17:40 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/12 06:28:50 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include "libft/libft.h"

// TODO: this is somehow really fucked up. how can i sort a stack only through
// rotating and swapping? must be possible.
void	swap_sort(t_stacks **sts)
{
	long	*ss;

	ss = quicksorted_stack((*sts)->a->st, (*sts)->a->size);
	free(ss);
}
