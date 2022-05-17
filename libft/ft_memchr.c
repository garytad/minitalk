/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slim <slim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:01 by slim              #+#    #+#             */
/*   Updated: 2022/05/17 15:43:02 by slim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
