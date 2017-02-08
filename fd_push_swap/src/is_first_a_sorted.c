/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_first_a_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:58:03 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 15:58:37 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_first_a_sorted(t_list *start_a)
{
	t_list	*tmp;

	tmp = start_a;
	while (tmp && tmp->next && tmp->next != start_a)
	{
		if ((*(int*)tmp->content) > (*(int*)(tmp->next)->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
