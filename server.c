/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:49:25 by fmaurer           #+#    #+#             */
/*   Updated: 2024/09/01 00:02:33 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "signal.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static unsigned char c;

	(void)context;
	if (signum == SIGUSR2)
		c |= (128 >> i); // TODO find most obvious way of doing this.
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			write(1, "\n", 1);

		}
		else
			write(1, &c, 1);
		c = 0;
		i = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_printf("Server failed to send SIGUSR2");
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_printf("Server failed to send SIGUSR1");
}

int	main(void)
{
	pid_t	pid;
	struct	sigaction action;

	pid = getpid();
	ft_printf("%d\n", pid);

	action.sa_sigaction = &signal_handler;
	action.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
