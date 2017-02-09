/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:23:43 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/09 09:23:29 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_a_first(t_list **start_a, t_list **start_b,
		int median, char *opsresult)
{
	t_vars	param;
	t_list	*tmp;

	ft_bzero(&param, sizeof(param));
	param.tot_a = nb_of_elem(*start_a);
	tmp = *start_a;
	while (param.i < param.tot_a)
	{
		if ((*(int*)tmp->content) >= median)
		{
			tmp = tmp->next;
			*start_a = (*start_a)->next;
			ft_strcat(opsresult, "ra\n");
		}
		else if ((*(int*)tmp->content) < median)
		{
			param.lot++;
			ft_push_elem(start_a, start_b);
			(*start_b)->lot = param.lot;
			tmp = *start_a;
			ft_strcat(opsresult, "pb\n");
		}
		param.i++;
	}
}

void	ft_main_algo(t_list *start_a, char *opsresult)
{
	t_list **start_b;

	if ((start_b = malloc(sizeof(t_list*))) == NULL)
		exit(0);
	*start_b = NULL;
	while (nb_of_elem(start_a) >= 3)
		split_a_first(&start_a, start_b,
				find_med_lst2(start_a, nb_of_elem(start_a)), opsresult);
	order_in_place_a(&start_a, opsresult);
	while (*start_b)
	{
		get_rid_of_b(&start_a, start_b,
				find_med_lst2(*start_b, (*start_b)->lot), opsresult);
		order_in_place_a(&start_a, opsresult);
		while ((start_a)->lot >= 3)
			get_rid_of_a(&start_a, start_b,
					find_med_lst2(start_a, start_a->lot), opsresult);
		order_in_place_a(&start_a, opsresult);
	}
	free(start_b);
}
