#include <signal.h>
#include "libft/libft.h"
#include <stdio.h>

int	send_string_pid(int pid, char *str)
{
	unsigned char	counter;
	int				i;

	i = 0;
	while (str[i])
	{
		counter = 128;
		while (counter)
		{
			if (counter & str[i])
			{
				if (kill(pid, SIGUSR1) == -1)
					return (0);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					return (0);
			}
			counter >>= 1;
			usleep(100);
		}
		i++;
	}
	return (1);
}

int	send_0_pid(int pid)
{
	int	i;

	i = 8;
	while (i-- > 0)
	{
		if (kill(pid, SIGUSR2) == -1)
			return (0);
		usleep(100);
	}
	return (1);
}

void	sighandler(int sig)
{
	static int	i;

	if (sig == SIGUSR2)
	{
		i++;
	}
	else
	{
		write(1, "Data Received : ", 16);
		ft_putnbr_fd(i, 1);
		write(1, "\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	write(1, "Data Sent : ", 12);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	write(1, "\n", 1);
	send_string_pid(ft_atoi(argv[1]), argv[2]);
	send_0_pid(ft_atoi(argv[1]));
	sleep(3);
	write(1, "Data send failed.\n", 18);
	return (1);
}
