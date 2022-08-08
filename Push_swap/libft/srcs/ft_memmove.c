/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:10:27 by schuah            #+#    #+#             */
/*   Updated: 2022/07/04 18:50:07 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;

	i = -1;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		i = (int)n;
		while (--i >= 0)
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		return (dst);
	}
	else
	{
		while (++i < (int)n)
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
	}
	return (dst);
}
