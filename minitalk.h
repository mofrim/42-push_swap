/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:48:43 by fmaurer           #+#    #+#             */
/*   Updated: 2024/09/01 01:59:18 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <errno.h>

# define TIMEOUT 20

void	exit_error(char *msg);
void 	print_bitstr(unsigned char c);
void	signal_setup(void (*sig_handler)(int));

#endif
