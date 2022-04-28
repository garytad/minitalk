#include <signal.h>
#include "libft/libft.h"

void	print_bits(int sig, siginfo_t *info, void *ucontext)
{
	static int	i;
	static char	c;

	(void)ucontext;
	i++;
	if (sig == SIGUSR1)
		c |= 1;
	if (i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		write (1, &c, 1);
		kill(info->si_pid, SIGUSR2);
		c = 0;
	}
	else
	{
		c <<= 1;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &print_bits;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "Server PID : ", 13);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
