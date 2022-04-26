#include "libft.h"

static int	find_int_len(int n)
{
	int				len;
	unsigned int	ncpy;

	len = 0;
	if (n < 0)
	{
		ncpy = -n;
		len++;
	}
	if (n == 0)
		return (1);
	if (n > 0)
		ncpy = n;
	while (ncpy)
	{
		ncpy /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				nlen;
	unsigned int	ncpy;

	nlen = find_int_len(n);
	str = malloc(nlen + 1);
	ncpy = 0;
	if (!str)
		return (0);
	if (n < 0)
	{
		ncpy = -n;
		str[0] = '-';
	}
	if (n > 0)
		ncpy = n;
	if (ncpy == 0)
		str[0] = '0';
	while (ncpy)
	{
		str[--nlen] = ncpy % 10 + '0';
		ncpy /= 10;
	}
	str[find_int_len(n)] = '\0';
	return (str);
}
