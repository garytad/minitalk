#include <signal.h>

int	ft_atoi(const char *str)
{
	int		sign;
	int		res;
	int		i;

	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		return (-res);
	else
		return (res);
}

int	send_string_pid(int pid, unsigned char *str)
{
	unsigned char	counter;

	counter = 128;
	while (*str)
	{
		while (counter)
		{
			if (counter & *str)
				if (kill(pid, SIGUSR1) == -1)
					return (0);
			else
				if (kill(pid, SIGUSR2) == -1)
					return (0);
			counter >>= 1;
		}
		*str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	send_string_pid(ft_atoi(argv[1]), argv[2]);
	sleep(5);

}
