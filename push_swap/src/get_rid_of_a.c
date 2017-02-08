/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rid_of_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:53:42 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 16:29:15 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rid_of_a_two(t_list **start_a, char *opsresult)
{
	if ((*(int*)(*start_a)->content) > (*(int*)(*start_a)->next->content))
	{
		ft_do_swap(start_a);
		ft_strcat(opsresult, "sa\n");
	}
	(*start_a)->lot = 1;
}

void	get_rid_of_a_three(t_list **start_a, t_list **start_b,
		char *opsresult, t_vars *param)
{
	if ((*(int*)(*start_a)->content) >= param->median)
	{
		(*start_a) = (*start_a)->next;
		ft_strcat(opsresult, "ra\n");
		param->next++;
	}
	else if ((*(int*)(*start_a)->content) < param->median)
	{
		param->lot++;
		ft_strcat(opsresult, "pb\n");
		ft_push_elem(start_a, start_b);
		(*start_b)->lot = param->lot;
	}
	param->i++;
}

void	get_rid_of_a(t_list **start_a, t_list **start_b,
		int median, char *opsresult)
{
	t_vars param;

	param.i = 0;
	param.next = 0;
	param.lot = 0;
	param.taille = (*start_a)->lot;
	param.median = median;
	if (param.taille == 2)
	{
		if ((*(int*)(*start_a)->content) > (*(int*)(*start_a)->next->content))
			get_rid_of_a_two(start_a, opsresult);
		return ;
	}
	while (param.i < param.taille)
		get_rid_of_a_three(start_a, start_b, opsresult, &param);
	while (param.next)
	{
		(*start_a) = (*start_a)->previous;
		ft_strcat(opsresult, "rra\n");
		param.next--;
	}
	(*start_a)->lot = param.taille - param.lot;
}
