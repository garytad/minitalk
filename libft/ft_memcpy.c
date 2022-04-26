#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char const	*psrc;
	char		*pdst;
	size_t		i;

	if (src == 0 && dst == 0)
		return (0);
	psrc = (char const *)src;
	pdst = (char *)dst;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}
