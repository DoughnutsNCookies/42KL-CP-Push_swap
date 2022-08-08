/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:42:09 by schuah            #+#    #+#             */
/*   Updated: 2022/07/30 17:57:16 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_H
# define PS_BONUS_H

# include "../libft/srcs/libft.h"
# include "../libft/srcs/ft_printf.h"

typedef struct s_psinfo
{
	int	len_a;
	int	len_b;
	int	total_len;
	int	mp;
	int	*stack_a;
	int	*stack_b;
}	t_psinfo;

/* Getter functions */
int		get_data(t_psinfo *psinfo, char **av);
int		*get_stack(t_psinfo *psinfo, char c);
void	get_converted_stack(t_psinfo *psinfo);
int		get_error(t_psinfo *psinfo, char *str, int j);
int		check_empty(char *str);

/* Quick sort function to sort an array */
void	quicksort(int *array, int low, int high);
int		is_sorted(int *array, int len);

/* Sorting functinos len <= 5 */
int		sort_small(t_psinfo *psinfo);
void	ps_sortthree(t_psinfo *psinfo);
void	ps_getthree(t_psinfo *psinfo, int *sorted_stack, int i, int sp);
void	ps_sortfive(t_psinfo *psinfo);

/* Sorting functions len > 5 */
int		smart_rotate(t_psinfo *psinfo);
void	sort_back(t_psinfo *psinfo);
void	make_stacks(t_psinfo *psinfo, int chunk_size, int n, int pa_count);
int		ps_sorthundred(t_psinfo *psinfo);

/* Operators */
void	stack_op(t_psinfo *psinfo, char *str);
void	ps_s(t_psinfo *psinfo, char *str, int print);
void	ps_p(t_psinfo *psinfo, char *str, int print);
void	ps_r(t_psinfo *psinfo, char *str, int print);
void	ps_rr(t_psinfo *psinfo, char *str, int print);

/* Helper function */
void	ps_printall(t_psinfo *psinfo);

#endif
