#include <signal.h>
#include <libft/libft.h>

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
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	send_string_pid(ft_atoi(argv[1]), argv[2]);
	send_0_pid(ft_atoi(argv[1]));
	return (1);
}
