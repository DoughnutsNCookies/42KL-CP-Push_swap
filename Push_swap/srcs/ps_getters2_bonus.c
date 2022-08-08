/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getters2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:49:39 by schuah            #+#    #+#             */
/*   Updated: 2022/07/30 20:00:53 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

/* Converts the input numbers into index form */
void	get_converted_stack(t_psinfo *psinfo)
{
	int	*sorted_tmp;
	int	len;
	int	i;
	int	j;

	sorted_tmp = get_stack(psinfo, 'a');
	ft_quicksort(sorted_tmp, 0, psinfo->len_a - 1);
	len = psinfo->len_a;
	i = 0;
	j = 0;
	while (len > 0)
	{
		if (psinfo->stack_a[i] == sorted_tmp[j])
		{
			psinfo->stack_a[i] = j;
			i++;
			len--;
			j = -1;
		}
		j++;
	}
	free(sorted_tmp);
}

/* Prints all data needed for debugging */
void	ps_printall(t_psinfo *psinfo)
{
	int	i;

	i = 0;
	ft_printf("\n|MP: %d|\n", psinfo->mp);
	ft_printf("|Len A: %d | Len B: %d|\n", psinfo->len_a, psinfo->len_b);
	while (i < psinfo->len_a || i < psinfo->len_b)
	{
		if (psinfo->stack_a[i] != 0)
			ft_printf("Stack A[%d]: %d\t\t\t\t", i, psinfo->stack_a[i]);
		else if (psinfo->stack_a[i] == 0 && i < psinfo->len_a)
			ft_printf("Stack A[%d]: %d\t\t\t\t", i, psinfo->stack_a[i]);
		else
			ft_printf("\t\t\t\t\t");
		if (i < psinfo->len_b)
			ft_printf("Stack B[%d]: %d", i, psinfo->stack_b[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

/* Returns errno if there are any error present, 0 if none */
int	get_error(t_psinfo *psinfo, char *str, int j)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (str[i] == '-' && ft_isdigit(str[i + 1]))
				continue ;
			return (1);
		}
	}
	if (ft_atoi(str) < -2147483648)
		return (1);
	if (ft_atoi(str) > 2147483647)
		return (1);
	i = -1;
	while (++i < j)
		if (psinfo->stack_a[i] == ft_atoi(str))
			return (1);
	return (0);
}

/* Checks whether the array is sorted */
int	is_sorted(int *array, int len)
{
	int	i;

	i = 0;
	while (++i < len)
	{
		if (array[i - 1] > array[i])
			return (0);
	}
	return (1);
}

/* Checks whether the string has numbers in it */
int	check_empty(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (ft_isdigit(str[i]))
			return (0);
	return (1);
}
