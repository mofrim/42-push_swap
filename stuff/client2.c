/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:33:09 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/31 23:56:10 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"

typedef struct {
    int received_bits;
} ClientState;

void sig_handler(int signum, siginfo_t *info, void *context)
{
    if (info == NULL || info->si_value.sival_ptr == NULL) {
        ft_printf("Error: Invalid signal info\n");
        return;
    }
    ClientState *state = (ClientState *)info->si_value.sival_ptr;
    if (signum == SIGUSR2)
        ft_printf("char received!\n");
    if (signum == SIGUSR1)
        state->received_bits++;
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

int sendchar(unsigned char c, int pid, ClientState *state)
{
    int bit_indx;
    int old_received_bits;

    bit_indx = 0;
    ft_printf("Sending char \'%c\' = ", c);
    print_bitstr(c);
    while (bit_indx < 8)
    {
        if ((c << bit_indx) & 0b10000000)
        {
            old_received_bits = state->received_bits;
            kill(pid, SIGUSR2);
            usleep(10);
            while (state->received_bits == old_received_bits)
            {
                ft_printf("waiting for ack\n");
                usleep(10);
            }
        }
        else
        {
            old_received_bits = state->received_bits;
            kill(pid, SIGUSR1);
            usleep(10);
            while (state->received_bits == old_received_bits)
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

int main(int ac, char **av)
{
    pid_t srv_pid;
    char *ptr;
    struct sigaction act;
    ClientState state = {0}; // Initialize ClientState

    act.sa_sigaction = sig_handler;
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
        sendchar((unsigned char)*ptr, srv_pid, &state);
        ptr++;
    }
    sendchar('\0', srv_pid, &state);
    return (0);
}
// ```
//
// These changes modify the main function to create a local ClientState struct and pass it to the sendchar function. We also update the sigaction setup to use SA_SIGINFO and pass the address of the state struct to the signal handler.
