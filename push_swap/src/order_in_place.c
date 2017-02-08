/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_in_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:35:36 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/07 15:35:46 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_in_place_a(t_list **start_a, char *opsresult)
{
	if (is_first_a_sorted(*start_a))
		return ;
	else if (nb_of_elem(*start_a) == 2)
	{
		ft_do_swap(start_a);
		ft_strcat(opsresult, "sa\n");
	}
	else
	{
		if (*(int*)(*start_a)->content > *(int*)(*start_a)->next->content
				&& *(int*)(*start_a)->content < *(int*)(*start_a)->previous->content)
		{
			ft_do_swap(start_a);
			ft_strcat(opsresult, "sa\n");
		}
		else if (*(int*)(*start_a)->content < *(int*)(*start_a)->next->content
				&& *(int*)(*start_a)->content > *(int*)(*start_a)->previous->content)
		{
			ft_strcat(opsresult, "rra\n");
			ft_do_rev_rotate(start_a);
		}
		else if (*(int*)(*start_a)->content > *(int*)(*start_a)->next->content
				&& *(int*)(*start_a)->content > *(int*)(*start_a)->previous->content)
		{
			if (*(int*)(*start_a)->previous->content > *(int*)(*start_a)->next->content)
			{
				ft_strcat(opsresult, "ra\n");
				ft_do_rotate(start_a);
			}
			else
			{
				ft_strcat(opsresult, "sa\nrra\n");
				ft_do_swap(start_a);
				ft_do_rev_rotate(start_a);
			}
		}
		else if (*(int*)(*start_a)->content < *(int*)(*start_a)->next->content
				&& *(int*)(*start_a)->content < *(int*)(*start_a)->previous->content)
		{
			ft_strcat(opsresult, "ra\nsa\nrra\n");
			ft_do_rotate(start_a);
			ft_do_swap(start_a);
			ft_do_rev_rotate(start_a);
		}
	}
}
