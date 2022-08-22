/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorthundred_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:18:10 by schuah            #+#    #+#             */
/*   Updated: 2022/07/30 15:40:16 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

/* Checks whether the top of stack B can be pushed onto stack A */
int	can_push(t_psinfo *psinfo, int swap)
{
	int	*sorted_stack;

	sorted_stack = get_stack(psinfo, 'b');
	ft_quicksort(sorted_stack, 0, psinfo->len_b - 1);
	if (psinfo->stack_b[0] == sorted_stack[psinfo->len_b - 2] && swap == 0)
	{
		stack_op(psinfo, "pa");
		free(sorted_stack);
		return (1);
	}
	free(sorted_stack);
	return (0);
}

/* Finds the lowest possible move that a candidate needs to rotate
** and to be push over */
int	smart_rotate(t_psinfo *psinfo)
{
	int	swap;
	int	size;
	int	i;

	swap = 0;
	i = 0;
	size = psinfo->len_b;
	while (psinfo->stack_b[i] != size - 1)
		i++;
	while (psinfo->stack_b[0] != size - 1)
	{
		if (can_push(psinfo, swap) == 0)
		{
			if (i > size / 2)
				stack_op(psinfo, "rrb");
			else
				stack_op(psinfo, "rb");
		}
		else
			swap = 1;
	}
	return (swap);
}

/* Starts pushing back numbers from stack B to stack A */
void	sort_back(t_psinfo *psinfo)
{
	while (psinfo->len_b != 0)
	{
		if (smart_rotate(psinfo))
		{
			stack_op(psinfo, "pa");
			if (psinfo->len_b > 1 && psinfo->stack_b[0] < psinfo->stack_b[1])
				stack_op(psinfo, "ss");
			else
				stack_op(psinfo, "sa");
		}
		else
			stack_op(psinfo, "pa");
	}
}

/* Push numbers from stack A to form chunks on stack B,
** the smaller the number, the more middle it is on stack B */
void	make_stacks(t_psinfo *psinfo, int chunk_size, int n, int pa_count)
{
	while (psinfo->len_a)
	{
		if (psinfo->stack_a[0] < (chunk_size * n))
		{
			stack_op(psinfo, "pb");
			if (psinfo->stack_b[0] < chunk_size * n - (chunk_size / 2))
				stack_op(psinfo, "rb");
			pa_count++;
		}
		else
			stack_op(psinfo, "ra");
		if (pa_count == chunk_size * n
			&& chunk_size * n < psinfo->total_len)
				n++;
	}
}

/* Main function for sorting below 100 numbers */
int	ps_sorthundred(t_psinfo *psinfo)
{
	int	chunk_size;

	chunk_size = psinfo->len_a / 12 + 30;
	make_stacks(psinfo, chunk_size, 1, 0);
	sort_back(psinfo);
	return (0);
}
