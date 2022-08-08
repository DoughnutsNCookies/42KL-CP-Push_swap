/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operators_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:26:55 by schuah            #+#    #+#             */
/*   Updated: 2022/07/30 16:39:15 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* List of operations to manipulate the stack */
int	stack_op(t_psinfo *psinfo, char *str)
{
	if (ft_strncmp(str, "sa", 3) == 0 || ft_strncmp(str, "sb", 3) == 0
		|| ft_strncmp(str, "ss", 3) == 0)
		ps_s(psinfo, str, 0);
	else if (ft_strncmp(str, "pa", 3) == 0 || ft_strncmp(str, "pb", 3) == 0)
		ps_p(psinfo, str, 0);
	else if (ft_strncmp(str, "rra", 4) == 0 || ft_strncmp(str, "rrb", 4) == 0
		|| ft_strncmp(str, "rrr", 4) == 0)
		ps_rr(psinfo, str, 0);
	else if (ft_strncmp(str, "ra", 3) == 0 || ft_strncmp(str, "rb", 3) == 0
		|| ft_strncmp(str, "rr", 3) == 0)
		ps_r(psinfo, str, 0);
	else
		return (ft_printf("Error: Invalid instruction\n"));
	return (0);
}

/* Swap the first 2 numbers at the top of the stack */
void	ps_s(t_psinfo *psinfo, char *str, int print)
{
	if (ft_strncmp(str, "sa", 3) == 0 && psinfo->len_a > 1)
		ft_swap(&psinfo->stack_a[0], &psinfo->stack_a[1]);
	if (ft_strncmp(str, "sb", 3) == 0 && psinfo->len_b > 1)
		ft_swap(&psinfo->stack_b[0], &psinfo->stack_b[1]);
	if (ft_strncmp(str, "ss", 3) == 0)
	{
		ps_s(psinfo, "sa", 0);
		ps_s(psinfo, "sb", 0);
	}
	if (print)
		ft_printf("%s\n", str);
}

/* Pushes the first element of stack A to stack B */
void	ps_p(t_psinfo *psinfo, char *str, int print)
{
	if (ft_strncmp(str, "pa", 3) == 0 && psinfo->len_b > 0)
	{
		ft_swap(&psinfo->stack_b[0], &psinfo->stack_a[psinfo->len_a]);
		ps_r(psinfo, "rb", 0);
		psinfo->len_a++;
		psinfo->len_b--;
		ps_rr(psinfo, "rra", 0);
	}
	if (ft_strncmp(str, "pb", 3) == 0 && psinfo->len_a > 0)
	{
		ft_swap(&psinfo->stack_a[0], &psinfo->stack_b[psinfo->len_b]);
		ps_r(psinfo, "ra", 0);
		psinfo->len_b++;
		psinfo->len_a--;
		ps_rr(psinfo, "rrb", 0);
	}
	if (print)
		ft_printf("%s\n", str);
}

/* Shift up all elements of the stack by one (first becomes last) */
void	ps_r(t_psinfo *psinfo, char *str, int print)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "ra", 3) == 0)
	{
		if (psinfo->len_a < 1)
			return ;
		while (++i < psinfo->len_a)
			ft_swap(&psinfo->stack_a[i], &psinfo->stack_a[i - 1]);
	}
	if (ft_strncmp(str, "rb", 3) == 0)
	{
		if (psinfo->len_b < 1)
			return ;
		while (++i < psinfo->len_b)
			ft_swap(&psinfo->stack_b[i], &psinfo->stack_b[i - 1]);
	}
	if (ft_strncmp(str, "rr", 3) == 0)
	{
		ps_r(psinfo, "ra", 0);
		ps_r(psinfo, "rb", 0);
	}
	if (print)
		ft_printf("%s\n", str);
}

/* Shift down all elements of the stack by one (last becomes first) */
void	ps_rr(t_psinfo *psinfo, char *str, int print)
{
	int	len;

	if (ft_strncmp(str, "rra", 3) == 0)
	{
		len = psinfo->len_a;
		if (len < 1)
			return ;
		while (len-- > 1)
			ft_swap(&psinfo->stack_a[len], &psinfo->stack_a[len - 1]);
	}
	if (ft_strncmp(str, "rrb", 3) == 0)
	{
		len = psinfo->len_b;
		if (len < 1)
			return ;
		while (len-- > 1)
			ft_swap(&psinfo->stack_b[len], &psinfo->stack_b[len - 1]);
	}
	if (ft_strncmp(str, "rrr", 3) == 0)
	{
		ps_rr(psinfo, "rra", 0);
		ps_rr(psinfo, "rrb", 0);
	}
	if (print)
		ft_printf("%s\n", str);
}
