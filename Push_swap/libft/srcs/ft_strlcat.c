/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:42:56 by schuah            #+#    #+#             */
/*   Updated: 2022/07/07 10:29:41 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	index;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	dest_length = ft_strlen(dest);
	index = 0;
	while ((dest_length < size - 1) && src[index] != '\0')
		dest[dest_length++] = src[index++];
	dest[dest_length] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[index]));
}
