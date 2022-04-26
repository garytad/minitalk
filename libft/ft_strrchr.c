#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	ch;
	char	*ptr;

	ch = (char)c;
	ptr = (char *)str;
	i = 0;
	while (ptr[i])
		i++;
	while (i >= 0)
	{
		if (ptr[i] == ch)
			return (ptr + i);
		i--;
	}
	return (0);
}
