#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	char				*ptr;
	unsigned char		cc;

	ptr = (char *)b;
	cc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = cc;
		i++;
	}
	return (b);
}
