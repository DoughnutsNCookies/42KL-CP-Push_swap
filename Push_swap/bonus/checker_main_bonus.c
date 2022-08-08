/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:25:50 by schuah            #+#    #+#             */
/*   Updated: 2022/07/30 16:39:06 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	read_instruction(t_psinfo *psinfo)
{
	char	*str;
	char	*temp;
	char	*temp2;
	int		error;

	str = get_next_line(STDIN_FILENO);
	while (str != 0)
	{
		temp = ft_strtrim(str, "\n");
		temp2 = str;
		error = stack_op(psinfo, temp);
		free(temp);
		free(temp2);
		if (error != 0)
			return (0);
		str = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(psinfo->stack_a, psinfo->len_a) && psinfo->len_b == 0)
		return (ft_printf("OK\n"));
	else
		return (ft_printf("KO\n"));
}

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
		if (get_data(psinfo, av) == 0)
			read_instruction(psinfo);
		free_everything(psinfo);
	}
	return (0);
}
