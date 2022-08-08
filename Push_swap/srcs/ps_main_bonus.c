/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:41:39 by schuah            #+#    #+#             */
/*   Updated: 2022/07/30 16:19:15 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

/* Frees everything that had used malloc */
static void	free_everything(t_psinfo *psinfo)
{
	free(psinfo->stack_b);
	free(psinfo->stack_a);
	free(psinfo);
}

/* Sets the default value / initializing values to the struct */
static void	default_flag_ps(t_psinfo *psinfo)
{
	psinfo->len_a = 0;
	psinfo->len_b = 0;
	psinfo->total_len = 0;
	psinfo->mp = 0;
	psinfo->stack_a = NULL;
	psinfo->stack_b = NULL;
}

/* Start of the main function */
int	main(int ac, char **av)
{
	t_psinfo	*psinfo;

	if (ac > 1)
	{
		psinfo = malloc(sizeof(t_psinfo));
		default_flag_ps(psinfo);
		get_data(psinfo, av);
		free_everything(psinfo);
	}
	return (0);
}
