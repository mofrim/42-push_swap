
// To handle Unicode characters in C, you need to modify the code to support wide characters and use functions that can handle them. This involves using `wchar_t` instead of `char` and functions like `wprintf` and `wcslen` for wide character strings. Here are the necessary changes:
//
// Replace lines: 13-14
// ```c
#include "../includes/minitalk.h"
#include <wchar.h>
// ```
//
// Replace lines: 25-26
// ```c
	if (*argv[2] == 0)
		handle_errors("Invalid message (empty)");
// ```
//
// Replace lines: 29-48
// ```c
void	send_msg(pid_t sv_pid, wchar_t *msg)
{
	wchar_t	c;
	int		nbr_bits;

	while (*msg)
	{
		c = *msg;
		nbr_bits = sizeof(wchar_t) * 8;
		while (nbr_bits--)
		{
			if (c & ((wchar_t)1 << (sizeof(wchar_t) * 8 - 1)))
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		msg++;
	}
}
// ```
//
// Replace lines: 69-78
// ```c
int	main(int argc, char **argv)
{
	pid_t		sv_pid;
	wchar_t		*msg;

	args_check(argc, argv);
	sv_pid = ft_atoi(argv[1]);
	ft_printf("CLIENT PID = %d\n", getpid());
	config_signals();
	msg = (wchar_t *)argv[2];
	send_msg(sv_pid, msg);
	return (EXIT_SUCCESS);
}
// ```
//
// Explanation:
// 1. **Include `wchar.h`**: This header is necessary for wide character support.
// 2. **Modify `send_msg` function**: Change the `char` type to `wchar_t` to handle wide characters. Adjust the bit manipulation to account for the size of `wchar_t`.
// 3. **Modify `main` function**: Convert the message argument to `wchar_t` before passing it to `send_msg`.
//
// These changes ensure that the program can handle Unicode characters properly.
