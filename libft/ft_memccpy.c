#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char		*psrc;
	unsigned char			*pdst;
	unsigned char			ch;
	size_t					i;

	if (src == 0 && dst == 0)
		return (0);
	ch = (unsigned char)c;
	psrc = (unsigned const char *)src;
	pdst = (unsigned char *)dst;
	i = 0;
	while (i < n && ch != 0)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
