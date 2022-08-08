/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:19:17 by schuah            #+#    #+#             */
/*   Updated: 2022/07/29 21:19:30 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned int n, char *base)
{
	int				i;
	char			*output;
	unsigned int	temp;

	i = 1;
	temp = n;
	while (temp >= 16 && (temp / 16) > 0 && ++i)
		temp /= 16;
	output = malloc(sizeof(char) * (i + 1));
	output[i] = '\0';
	while (n >= 16)
	{
		output[--i] = base[n % 16];
		n /= 16;
	}
	output[--i] = base[n % 16];
	return (output);
}
