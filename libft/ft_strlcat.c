/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slim <slim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:56 by slim              #+#    #+#             */
/*   Updated: 2022/05/17 15:43:56 by slim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	offset;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	offset = dlen;
	i = 0;
	if (dstsize == 0)
		return (slen);
	if (dstsize < dlen)
		return (slen + dstsize);
	while (src[i] && offset < dstsize - 1)
	{
		dst[offset] = src[i];
		offset++;
		i++;
	}
	dst[offset] = '\0';
	return (dlen + slen);
}
