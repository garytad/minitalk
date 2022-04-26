#include "libft.h"
#include "stdio.h"

static int	splitcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		start;
	int		sc;

	i = 0;
	j = 0;
	start = 0;
	sc = splitcount(s, c);
	ptr = malloc(sizeof(char *) * (splitcount(s, c) + 1));
	if (!ptr)
		return (0);
	while (sc--)
	{
		while (s[j] == c)
			j++;
		start = j;
		while ((s[j] != c) && (s[j]))
			j++;
		ptr[i++] = ft_substr(s, start, (j - start));
	}
	ptr[i] = 0;
	return (ptr);
}
