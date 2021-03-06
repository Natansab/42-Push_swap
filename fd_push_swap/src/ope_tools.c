/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:46:19 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/09 09:31:43 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_is_sorted(t_list **start_a, t_list **start_b)
{
	t_list	*tmp;
	int		error;

	error = 0;
	if (*start_b)
		error = 1;
	tmp = *start_a;
	while (tmp && tmp->next && tmp->next != *start_a)
	{
		if ((*(int*)tmp->content) > (*(int*)(tmp->next)->content))
			error = 1;
		tmp = tmp->next;
	}
	free_lst(*start_a);
	free_lst(*start_b);
	free(start_b);
	if (error)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
}

void	ft_operation(char *line, t_list **start_a, t_list **start_b)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") ||
		!ft_strcmp(line, "ss"))
		ft_swap_elem(line, start_a, start_b);
	else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") ||
		!ft_strcmp(line, "rr"))
		ft_rotate_elem(line, start_a, start_b);
	else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") ||
		!ft_strcmp(line, "rrr"))
		ft_rev_rotate_elem(line, start_a, start_b);
	else if (!ft_strcmp(line, "pb") && *start_a)
		ft_push_elem(start_a, start_b);
	else if (!ft_strcmp(line, "pa") && *start_b)
		ft_push_elem(start_b, start_a);
	else if (ft_strcmp(line, "pa") && ft_strcmp(line, "pb"))
	{
		free_lst(*start_b);
		ft_exit_free_a(*start_a);
	}
}
