/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:40:08 by fmaurer           #+#    #+#             */
/*   Updated: 2024/09/01 00:05:55 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

static int	g_bits_received;

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("char received!\n");
	if (signum == SIGUSR1)
		g_bits_received++;
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

/* SIGUSR1 = 0, SIGUSR2 = 1 */
int	sendchar(unsigned char c, int pid)
{
	int	bit_indx;
	int	old_received_bits;

	bit_indx = 0;
	ft_printf("Sending char \'%c\' = ", c);
	print_bitstr(c);
	while (bit_indx < 8)
	{
		if ((c << bit_indx) & 0b10000000)
		{
			old_received_bits = g_bits_received;
			kill(pid, SIGUSR2);
			usleep(10);
			while (g_bits_received == old_received_bits)
			{
				ft_printf("waiting for ack\n");
				usleep(10);
			}
		}
		else
		{
			old_received_bits = g_bits_received;
			kill(pid, SIGUSR1);
			usleep(10);
			while (g_bits_received == old_received_bits)
			{
				ft_printf("waiting for ack\n");
				usleep(10);
			}
		}
		bit_indx++;
	}
	ft_printf("\n");
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	srv_pid;
	char	*ptr;
	struct sigaction	act;

	act.sa_handler = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		ft_printf("sigaction error\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_printf("sigaction error\n");
		exit(1);
	}
	if (ac < 3)
	{
		ft_printf("Usage: %s SERVER_PID MESSAGE\n", av[0]);
		return (0);
	}
	srv_pid = ft_atoi(av[1]);
	if (kill(srv_pid, 0))
	{
		ft_printf("Wrong PID.\n");
		exit(ESRCH);
	}
	ptr = av[2];
	ft_printf("Sending message:\n\t\"%s\"\n to PID %d\n\n", ptr, srv_pid);
	while (*ptr)
	{
		sendchar((unsigned char)*ptr, srv_pid);
		ptr++;
	}
	sendchar('\0', srv_pid);
	return (0);
}


