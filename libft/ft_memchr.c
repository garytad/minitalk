#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	ch;
	size_t			i;

	ps = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while ((n--) && (ps != 0))
	{
		if (ps[i] != ch)
			i++;
		else
			return (ps + i);
	}
	return (0);
}
