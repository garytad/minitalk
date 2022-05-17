/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slim <slim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:39 by slim              #+#    #+#             */
/*   Updated: 2022/05/17 15:43:40 by slim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	ch;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	ch = (char)c;
	i = 0;
	while (ptr[i] && ptr[i] != ch)
	{
		i++;
	}
	if (ptr[i] == ch)
		return (ptr + i);
	return (0);
}
