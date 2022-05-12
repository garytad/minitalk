#include <signal.h>
#include "libft/libft.h"

/* *function send a string using SIGUSR1 and SIGUSR2 signal to pid
   *convert string into bit and send it bit by bit by
    using SIGUSR1 represents 1 and SIGUSR2 represents 0 */
int	send_string_pid(int pid, char *str)
{
	unsigned char	counter;
	int				i;

	i = -1;
	while (str[++i])
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
	}
	return (1);
}

/* *function send a char 0 by using signal to pid
   *server will stop printing when receive char 0*/
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

/* *handle SIGUSR2 signal as char printed on server side
   *handle SIGUSR1 signal as server has finished printed
   *function will write how many byte printed on server */
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

/* *function will use argv[1] as pid and argv[2] as string to send
   *print data sent and received if it receive back a signal
   *print data send failed if it does not receive back a signal */
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
