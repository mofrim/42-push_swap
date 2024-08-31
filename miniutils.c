/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:10:08 by fmaurer           #+#    #+#             */
/*   Updated: 2024/09/01 00:24:05 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	exit_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(errno);
} 

void print_bitstr(unsigned char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if(c & 0b10000000)
			ft_printf("1");
		else
			ft_printf("0");
		c <<= 1;
		i++;
	}
	ft_printf("\n");
}
