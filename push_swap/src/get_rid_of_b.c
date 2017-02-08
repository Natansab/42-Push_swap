/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rid_of_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:53:42 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 16:39:43 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rid_of_b_two(t_list **start_a, t_list **start_b, char *opsresult,
		t_vars *param)
{
	while (param->i < param->taille)
	{
		if ((*(int*)(*start_b)->content) < param->median && (*start_b)->next)
		{
			(*start_b) = (*start_b)->next;
			ft_strcat(opsresult, "rb\n");
			param->next++;
		}
		else if ((*(int*)(*start_b)->content) >= param->median)
		{
			param->lot++;
			ft_strcat(opsresult, "pa\n");
			ft_push_elem(start_b, start_a);
			(*start_a)->lot = param->lot;
		}
		param->i++;
	}
}

void	get_rid_of_b(t_list **start_a, t_list **start_b,
		int median, char *opsresult)
{
	t_vars	param;
	t_list	*tmp;

	ft_bzero(&param, sizeof(param));
	param.taille = (*start_b)->lot;
	param.median = median;
	get_rid_of_b_two(start_a, start_b, opsresult, &param);
	while (param.next && *start_b && nb_of_elem(*start_b) != 1)
	{
		(*start_b) = (*start_b)->previous;
		ft_strcat(opsresult, "rrb\n");
		param.next--;
	}
	if (param.taille == 1)
		return ;
	tmp = *start_b;
	param.i = 0;
	while (param.taille - param.lot - param.i && tmp)
	{
		tmp->lot = param.taille - param.lot - param.i;
		tmp = tmp->next;
		param.i++;
	}
}
