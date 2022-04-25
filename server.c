#include <signal.h>
#include <libft/libft.h>

void	print_bits(int sig, siginfo_t *info, void *ucontext)
{
	static int	i;
	static char	c;

	i++;
	if (i = 8)
	{
		if (!c)
		{
			kill(info->si_pid, SIGUSR1);
			return;
		}
		write (1, &c, 1);
		i = 0;
	}
	else
	{
		if (sig == SIGUSR1)
			c |= 1;
		c <<= 1;
	}
}

int	main()
{
	struct sigaction	sa;

	sa.sa_sigaction = &print_bits;
	sa.sa_flags; SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	while (1)
		pause();
	return (0);
}

