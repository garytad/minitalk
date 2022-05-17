/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slim <slim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:34:36 by slim              #+#    #+#             */
/*   Updated: 2022/05/17 14:38:07 by slim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

/* *function converts receive signal and converts it into char
   *SIGUSR1 represents 1 and SIGUSR2 represents 0
   *function will print char when it receive 8 bits */
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
			write (1, "\n", 1);
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

/* function print its PID and wait for signal */
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
