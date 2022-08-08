/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:21:24 by schuah            #+#    #+#             */
/*   Updated: 2022/07/30 15:35:29 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long n)
{
	unsigned long	temp;
	char			*output;
	int				count;

	count = 3;
	temp = n;
	while (temp >= 16 && (temp / 16) && ++count)
		temp /= 16;
	temp = n;
	output = malloc(sizeof(char) * (count + 1));
	if (output == NULL)
		return (NULL);
	output[count] = '\0';
	output[0] = '0';
	output[1] = 'x';
	while (temp >= 16)
	{
		--count;
		output[count] = "0123456789abcdef"[temp % 16];
		temp /= 16;
	}
	output[--count] = "0123456789abcdef"[temp % 16];
	return (output);
}
