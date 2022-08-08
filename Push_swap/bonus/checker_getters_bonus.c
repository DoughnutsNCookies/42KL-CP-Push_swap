/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_getters_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:17:52 by schuah            #+#    #+#             */
/*   Updated: 2022/07/30 19:52:01 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* Turns all input into a string of numbers seperated by spaces */
static char	*get_inputstr(t_psinfo *psinfo, char **av)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	*output;

	i = 0;
	output = malloc(sizeof(char));
	if (output == NULL)
		return (NULL);
	while (av[++i] != 0)
	{
		if (av[i][0] == '\0' || check_empty(av[i]))
		{
			free(output);
			return (NULL);
		}
		temp = ft_strjoin(output, av[i]);
		temp2 = output;
		output = ft_strjoin(temp, " ");
		free(temp2);
		free(temp);
	}
	psinfo->stack_a = malloc(sizeof(int) * ft_getwc(output, ' '));
	psinfo->stack_b = malloc(sizeof(int) * ft_getwc(output, ' '));
	return (output);
}

/* Converts the input numbers into index form */
static void	get_converted_stack(t_psinfo *psinfo)
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

/* Puts the numbers into stack A after calculating the number of inputs,
** Returns errno if there is any input errors, 0 if none */
static int	get_input_from_av(t_psinfo *psinfo, char **av)
{
	char	**numbers;
	char	*str;
	int		i;
	int		j;
	int		errno;

	str = get_inputstr(psinfo, av);
	if (str == NULL)
		return (1);
	if (psinfo->stack_a == NULL || psinfo->stack_b == NULL)
		return (0);
	numbers = ft_split(str, ' ');
	i = 0;
	j = 0;
	while (numbers[j] != 0)
	{
		if (errno == 0)
			errno = get_error(psinfo, numbers[j], j);
		psinfo->stack_a[i++] = ft_atoi(numbers[j]);
		free(numbers[j++]);
	}
	free(numbers);
	free(str);
	return (errno);
}

/* Calculates the number of input */
static void	get_input(t_psinfo *psinfo, char **av)
{
	int	i;
	int	j;

	i = 0;
	psinfo->len_a = 0;
	while (av[++i] != 0)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			while (ft_isspace(av[i][j]) || av[i][j] == '-' || av[i][j] == '+')
				j++;
			while (!ft_isspace(av[i][j]) && av[i][j] != '\0')
				j++;
			psinfo->len_a++;
			while (ft_isspace(av[i][j]) || av[i][j] == '-' || av[i][j] == '+')
				j++;
		}
	}
	psinfo->total_len = psinfo->len_a;
}

/* Gets necessary data and assigns the respective sorting algorithm,
** outputs the respective error messages based on the errno received */
int	get_data(t_psinfo *psinfo, char **av)
{
	get_input(psinfo, av);
	if (get_input_from_av(psinfo, av))
		return (write(2, "Error\n", 6));
	get_converted_stack(psinfo);
	return (0);
}
