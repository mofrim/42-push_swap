#include <signal.h>


int main(void)
{
	kill(-1, SIGUSR1);

	return (0);
}
