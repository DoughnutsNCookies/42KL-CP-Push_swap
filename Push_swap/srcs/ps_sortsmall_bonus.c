/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortsmall_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:18:55 by schuah            #+#    #+#             */
/*   Updated: 2022/07/30 13:57:04 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

/* Function for sorting smaller stacks (len <= 5) */
int	sort_small(t_psinfo *psinfo)
{
	if (psinfo->len_a <= 3)
		ps_sortthree(psinfo);
	else if (psinfo->len_a <= 5)
		ps_sortfive(psinfo);
	return (0);
}

/* Function that sorts stack of 3 or less */
void	ps_sortthree(t_psinfo *psinfo)
{
	int	*sorted_stack;
	int	mp;

	if (psinfo->len_a == 2)
		stack_op(psinfo, "sa");
	sorted_stack = get_stack(psinfo, 'a');
	ft_quicksort(sorted_stack, 0, psinfo->len_a - 1);
	mp = sorted_stack[psinfo->len_a / 2];
	if (psinfo->stack_a[2] == mp && psinfo->stack_a[0] > mp)
		stack_op(psinfo, "ra");
	else if (psinfo->stack_a[2] == mp && psinfo->stack_a[0] < mp)
	{
		stack_op(psinfo, "rra");
		stack_op(psinfo, "sa");
	}
	else if (psinfo->stack_a[2] < mp && psinfo->stack_a[0] == mp)
		stack_op(psinfo, "rra");
	else if (psinfo->stack_a[2] > mp && psinfo->stack_a[0] == mp)
		stack_op(psinfo, "sa");
	else if (psinfo->stack_a[2] < mp && psinfo->stack_a[0] > mp)
	{
		stack_op(psinfo, "ra");
		stack_op(psinfo, "sa");
	}
	free(sorted_stack);
}

/* Get stack A into 3 numbers by pushing smallest numbers into stack B */
void	ps_getthree(t_psinfo *psinfo, int *sorted_stack, int i, int sp)
{
	int	j;

	j = 0;
	while (i != 2 && ++j < 20)
	{
		if (psinfo->stack_a[0] == sp)
		{
			stack_op(psinfo, "pb");
			sp = sorted_stack[1];
			i++;
		}
		else
		{
			if (psinfo->stack_a[psinfo->len_a - 1] == sp)
				stack_op(psinfo, "rra");
			else
				stack_op(psinfo, "ra");
		}
	}
}

/* Function that sorts stack of 5 or less */
void	ps_sortfive(t_psinfo *psinfo)
{	
	int	*sorted_stack;
	int	sp;

	sorted_stack = get_stack(psinfo, 'a');
	ft_quicksort(sorted_stack, 0, psinfo->len_a - 1);
	sp = sorted_stack[0];
	ps_getthree(psinfo, sorted_stack, 0, sp);
	ps_sortthree(psinfo);
	free(sorted_stack);
	stack_op(psinfo, "pa");
	stack_op(psinfo, "pa");
}
