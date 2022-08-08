/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:43:55 by schuah            #+#    #+#             */
/*   Updated: 2022/07/05 16:06:57 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*output;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	output = malloc(sizeof(char) * (i + 1));
	if (output == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		output[i] = (*f)(i, s[i]);
	output[i] = '\0';
	return (output);
}
