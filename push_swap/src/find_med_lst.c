/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_med_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:29:42 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/02 19:12:09 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_med_lst(t_list *start_a)
{
	int		median;
	t_list*	tmp;
	t_list* tmp2;
	int		sup;
	int		inf;

	median = 0;
	tmp = start_a;
	while (tmp)
	{
		median = (*(int*)tmp->content);
		tmp2 = start_a;
		sup = 0;
		inf = 0;
		while (tmp2)
		{
			sup = (median >= (*(int*)tmp2->content)) ? sup + 1 : sup;
			inf = (median <= (*(int*)tmp2->content)) ? inf + 1 : inf;
			if (!tmp2->next && (sup == inf || sup == inf - 1 || sup == inf + 1))
				return(median);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (median);
}

int	find_med_lst2(t_list *start_a, int length)
{
	int		median;
	t_list*	tmp;
	t_list* tmp2;
	int		sup;
	int		inf;
	int		i;
	int		j;

	i = 0;
	median = 0;
	tmp = start_a;
	while (i < length)
	{
		median = (*(int*)tmp->content);
		tmp2 = start_a;
		sup = 0;
		inf = 0;
		j = 0;
		// printf("mediaaaane vaut %i\n", median);
		while (j < length)
		{
			sup = (median > (*(int*)tmp2->content)) ? sup + 1 : sup;
			inf = (median < (*(int*)tmp2->content)) ? inf + 1 : inf;
			// printf("\n\ncontent vaut %i\n", median);
			// printf("inf vaut %i\n", inf);
			// printf("sup vaut %i\n", sup);
			// printf("et j et length valent %i %i\n", j, length);

			if (j == (length - 1) && (((sup == inf + 1) && (length % 3)) ||
				((sup == inf) && (length % 2))))
			{
				// printf("####### median vaut %i #######\n", median);
				// printf("inf vaut %i", inf);
				// printf("sup vaut %i", sup);
				return(median);
			}

			tmp2 = tmp2->next;
			j++;
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}
