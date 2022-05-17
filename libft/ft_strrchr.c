/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slim <slim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:44:18 by slim              #+#    #+#             */
/*   Updated: 2022/05/17 15:44:19 by slim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	ch;
	char	*ptr;

	ch = (char)c;
	ptr = (char *)str;
	i = 0;
	while (ptr[i])
		i++;
	while (i >= 0)
	{
		if (ptr[i] == ch)
			return (ptr + i);
		i--;
	}
	return (0);
}
