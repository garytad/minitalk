/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slim <slim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:12 by slim              #+#    #+#             */
/*   Updated: 2022/05/17 15:43:13 by slim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	char const	*psrc;

	if (src == 0 && dst == 0)
		return (0);
	pdst = (char *)dst;
	psrc = (char const *)src;
	if (dst > src)
	{
		while (len--)
		{
			pdst[len] = psrc[len];
		}
	}
	else
	{
		while (len--)
		{
			*pdst++ = *psrc++;
		}
	}
	return (dst);
}
