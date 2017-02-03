/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:40:32 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/03 14:26:53 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_swap(t_list **stack)
{
	int pivot;

	pivot = *((int*)(*stack)->content);
	*((int*)(*stack)->content) = *((int*)((*stack)->next)->content);
	*((int*)((*stack)->next)->content) = pivot;
}

void	ft_do_psuh(t_list **src_pile, t_list **dst_pile)
{
	ft_push_elem(src_pile, dst_pile);
}

void	ft_do_rotate(t_list **stack)
{
	*stack = (*stack)->next;
}

void	ft_do_rev_rotate(t_list **stack)
{
	*stack = (*stack)->previous;
}
