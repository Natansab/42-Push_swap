/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:11:06 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 11:48:26 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_exit_free_a(t_list *start_a)
{
	ft_putstr_fd("Error\n", 2);
	free_lst(start_a);
	exit(0);
}

void	print_list(t_list **start_a)
{
	int		i;
	t_list	*tmp;

	if (!(*start_a))
	{
		ft_putstr("\n");
		return ;
	}
	tmp = *start_a;
	i = 0;
	while (tmp->next != *start_a && tmp->next)
	{
		ft_putnbr(*((int*)(tmp)->content));
		ft_putstr(" ");
		tmp = tmp->next;
		i++;
	}
	ft_putnbr(*((int*)(tmp)->content));
	ft_putstr("\n");
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && tmp->next && tmp->next != lst)
	{
		tmp = tmp->next;
		free((tmp->previous)->content);
		free(tmp->previous);
	}
	if (tmp)
		free(tmp);
}

void	linear_to_circular_lst(t_list *begin_lst)
{
	t_list *previous;
	t_list *tmp;

	if (!begin_lst || !(begin_lst->next))
		return ;
	tmp = begin_lst->next;
	previous = begin_lst;
	while (tmp->next)
	{
		tmp->previous = previous;
		previous = tmp;
		tmp = tmp->next;
	}
	tmp->previous = previous;
	tmp->next = begin_lst;
	begin_lst->previous = tmp;
}

int		nb_of_elem(t_list *begin_lst)
{
	t_list	*tmp;
	int		i;

	if (!(begin_lst))
	{
		return (0);
	}
	i = 1;
	tmp = begin_lst;
	while (tmp && tmp->next && tmp->next != begin_lst)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
