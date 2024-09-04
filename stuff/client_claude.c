
// To redesign the program without using any global variable, we need to make several changes. Here are the suggested modifications:
//
// Replace lines: 16-24
// ```c
typedef struct {
    int received_bits;
} ClientState;

void sig_handler(int signum, siginfo_t *info, void *context)
{
    ClientState *state = (ClientState *)info->si_value.sival_ptr;
    if (signum == SIGUSR2)
        ft_printf("char received!\n");
    if (signum == SIGUSR1)
        state->received_bits++;
}

// The `siginfo_t` struct is a data structure used in Unix-like operating systems to provide additional information about a signal when it is delivered to a process. It is typically used with the `SA_SIGINFO` flag in the `sigaction` structure to enable the delivery of extended signal information.
//
// Here are some key members of the `siginfo_t` struct:
//
// 1. `si_signo`: The signal number (e.g., SIGUSR1, SIGUSR2).
// 2. `si_code`: A code indicating why the signal was sent.
// 3. `si_pid`: The process ID of the sender.
// 4. `si_uid`: The real user ID of the sending process.
// 5. `si_status`: Exit value or signal for SIGCHLD.
// 6. `si_value`: Signal value, which can be used to pass data to the signal handler.
//
// In the given code, we're specifically using the `si_value` member to pass a pointer to the `ClientState` struct. This allows us to access and modify the `received_bits` counter within the signal handler without using global variables.
//
// To improve the code and make it more robust, we should add error checking for the `info` pointer and the `si_value.sival_ptr` value. Here's a suggested modification:
//
// Replace lines: 10-17
// ```c
// void sig_handler(int signum, siginfo_t *info, void *context)
// {
//     if (info == NULL || info->si_value.sival_ptr == NULL) {
//         ft_printf("Error: Invalid signal info\n");
//         return;
//     }
//     ClientState *state = (ClientState *)info->si_value.sival_ptr;
//     if (signum == SIGUSR2)
//         ft_printf("char received!\n");
//     if (signum == SIGUSR1)
//         state->received_bits++;
// }
// ```
//
// This change adds error checking to ensure that the `info` pointer and the `si_value.sival_ptr` are not NULL before attempting to use them. This helps prevent potential crashes or undefined behavior if the signal handler is called with unexpected parameters.
// ```
//
// This change replaces the global variable with a struct that holds the state. We also modify the signal handler to accept the additional parameters required for SA_SIGINFO.
//
// Replace lines: 43-79
// ```c
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
// ```
//
// This change modifies the sendchar function to accept a pointer to the ClientState struct instead of using the global variable.
//
// Replace lines: 81-122
// ```c
int main(int ac, char **av)
{
    pid_t srv_pid;
    char *ptr;
    struct sigaction act;
    ClientState state = {0};

    act.sa_sigaction = (void (*)(int, siginfo_t *, void *))sig_handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGUSR1);
    sigaddset(&act.sa_mask, SIGUSR2);
    act.sa_value.sival_ptr = &state;
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
