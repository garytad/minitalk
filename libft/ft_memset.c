/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slim <slim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:15 by slim              #+#    #+#             */
/*   Updated: 2022/05/17 15:43:16 by slim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
