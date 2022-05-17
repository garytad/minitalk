/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slim <slim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:44:14 by slim              #+#    #+#             */
/*   Updated: 2022/05/17 15:44:15 by slim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		nlen;
	char		*hay;

	hay = (char *)haystack;
	if (!(*needle))
		return (hay);
	nlen = ft_strlen(needle);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		while (needle[j] && hay[i + j]
			&& needle[j] == hay[i + j] && (i + j < len))
		{
			j++;
		}
		if (j == nlen)
			return (hay + i);
		i++;
	}
	return (0);
}
