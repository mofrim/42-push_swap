/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:40:08 by fmaurer           #+#    #+#             */
/*   Updated: 2024/09/01 02:07:37 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

static int	g_srv_ack;

void	sig_handler(int signum);
void	send_msg(int srv_pid, char *msg);
int		sendchar(unsigned char c, int pid, int *bits_sent);
void	send_sig(int pid, int signum);

int	main(int ac, char **av)
{
	pid_t	srv_pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s SERVER_PID MESSAGE\n", av[0]);
		return (0);
	}
	srv_pid = ft_atoi(av[1]);
	if (kill(srv_pid, 0) == -1)
		exit_error("Wrong PID.\n");
	signal_setup(&sig_handler);
	send_msg(srv_pid, av[2]);
	return (0);
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_printf(".");
	if (signum == SIGUSR1)
		g_srv_ack = 1;
}

void	send_msg(int srv_pid, char *msg)
{
	int	bits_sent;

	bits_sent = 0;
	ft_printf("Sending message to server at PID %d\n", srv_pid);
	while (*msg)
	{
		sendchar((unsigned char)*msg, srv_pid, &bits_sent);
		msg++;
	}
	sendchar('\0', srv_pid, &bits_sent);
	ft_printf(" done!\n%d bits sent\n", bits_sent);
}

/* SIGUSR1 = 0, SIGUSR2 = 1 */
int	sendchar(unsigned char c, int pid, int *bits_sent)
{
	int	bit_indx;

	bit_indx = 0;
	while (bit_indx < 8)
	{
		if ((c << bit_indx) & 0b10000000)
			send_sig(pid, SIGUSR2);
		else
			send_sig(pid, SIGUSR1);
		(*bits_sent)++;
		bit_indx++;
		g_srv_ack = 0;
	}
	return (0);
}

void	send_sig(int pid, int signum)
{
	int	timeout;

	timeout = 0;
	kill(pid, signum);
	usleep(10);
	while (!g_srv_ack && timeout < ACK_TIMEOUT)
	{
		ft_printf(" ");
		usleep(10);
		timeout++;
	}
	if (timeout == ACK_TIMEOUT && !g_srv_ack)
	{
		errno = ETIMEDOUT;
		exit_error("Server Timeout\n");
	}
}
