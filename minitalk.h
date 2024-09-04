/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:48:43 by fmaurer           #+#    #+#             */
/*   Updated: 2024/09/04 10:17:42 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <errno.h>

/* Timeout with error after 20*10ms = 200ms. */
# define ACK_TIMEOUT 20

void	exit_error(char *msg);
void	print_bitstr(unsigned char c);
void	signal_setup(void (*sig_handler)(int));

#endif
