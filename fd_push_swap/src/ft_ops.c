/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:46:38 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 19:32:14 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void	ft_push_elem_two(t_list **src_pile, t_list **dst_pile)
{
	if (nb_of_elem(*dst_pile) == 0)
	{
		*dst_pile = *src_pile;
		(*dst_pile)->next = NULL;
		(*dst_pile)->previous = NULL;
	}
	else if (nb_of_elem(*dst_pile) == 1)
	{
		(*src_pile)->previous = (*dst_pile);
		(*src_pile)->next = (*dst_pile);
		(*dst_pile)->previous = (*src_pile);
		(*dst_pile)->next = (*src_pile);
		(*dst_pile) = (*src_pile);
	}
	else if (nb_of_elem(*dst_pile) > 1)
	{
		(*src_pile)->previous = (*dst_pile)->previous;
		(*src_pile)->next = (*dst_pile);
		((*dst_pile)->previous)->next = *src_pile;
		(*dst_pile)->previous = *src_pile;
		*dst_pile = *src_pile;
	}
}

void	ft_push_elem(t_list **src_pile, t_list **dst_pile)
{
	t_list *pivot;

	pivot = (*src_pile)->next;
	if (nb_of_elem(*src_pile) > 2)
	{
		((*src_pile)->previous)->next = (*src_pile)->next;
		((*src_pile)->next)->previous = (*src_pile)->previous;
	}
	else if (nb_of_elem(*src_pile) == 2)
	{
		((*src_pile)->next)->next = NULL;
		((*src_pile)->next)->previous = NULL;
	}
	else if (nb_of_elem(*src_pile) == 1)
		pivot = NULL;
	ft_push_elem_two(src_pile, dst_pile);
	*src_pile = pivot;
}

void	ft_swap_elem(char *line, t_list **start_a, t_list **start_b)
{
	int pivot;

	if ((!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss")) &&
		nb_of_elem(*start_a) > 1)
	{
		pivot = *((int*)(*start_a)->content);
		*((int*)(*start_a)->content) = *((int*)((*start_a)->next)->content);
		*((int*)((*start_a)->next)->content) = pivot;
	}
	if ((!ft_strcmp(line, "sb") || !ft_strcmp(line, "ss")) &&
		nb_of_elem(*start_b) > 1)
	{
		pivot = *((int*)(*start_b)->content);
		*((int*)(*start_b)->content) = *((int*)((*start_b)->next)->content);
		*((int*)((*start_b)->next)->content) = pivot;
	}
}

void	ft_rotate_elem(char *line, t_list **start_a, t_list **start_b)
{
	if ((!ft_strcmp(line, "ra") || !ft_strcmp(line, "rr")) &&
		nb_of_elem(*start_a) > 1)
		(*start_a) = (*start_a)->next;
	if ((!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr")) &&
		nb_of_elem(*start_b) > 1)
		(*start_b) = (*start_b)->next;
}

void	ft_rev_rotate_elem(char *line, t_list **start_a, t_list **start_b)
{
	if ((!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr")) &&
		nb_of_elem(*start_a) > 1)
		(*start_a) = (*start_a)->previous;
	if ((!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr")) &&
		nb_of_elem(*start_b) > 1)
		(*start_b) = (*start_b)->previous;
}
