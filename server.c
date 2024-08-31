/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:49:25 by fmaurer           #+#    #+#             */
/*   Updated: 2024/09/01 00:21:27 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "signal.h"

// (unsigned char)128 = 10000000
// TODO find most obvious way of doing this.
void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	c;

	(void)context;
	if (signum == SIGUSR2)
		c |= (128 >> i);
	i++;
	if (i == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		i = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			exit_error("Server failed to send SIGUSR2");
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit_error("Server failed to send SIGUSR1");
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig_act;

	pid = getpid();
	ft_printf("%d\n", pid);
	sig_act.sa_sigaction = &signal_handler;
	sig_act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sig_act.sa_mask);
	sigaddset(&sig_act.sa_mask, SIGUSR1);
	sigaddset(&sig_act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	while (1)
		pause();
	return (0);
}
