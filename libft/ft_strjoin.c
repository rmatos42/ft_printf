/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:00:54 by rmatos            #+#    #+#             */
/*   Updated: 2016/09/29 17:49:48 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		size;
	int		i;
	size_t	j;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_strlen((char *)s1))
		result[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen((char *)s2))
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
