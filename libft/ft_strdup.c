/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:57:36 by rmatos            #+#    #+#             */
/*   Updated: 2016/09/23 15:04:44 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *result;

	result = ft_memalloc(ft_strlen((char*)str) + 1);
	if (!result)
		return (NULL);
	return (ft_strcpy(result, str));
}
