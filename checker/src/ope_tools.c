/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:46:19 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 11:56:05 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	read_ope(t_list **start_a, char **argv)
{
	char	*line;
	t_list	**start_b;

	if ((start_b = ft_memalloc(sizeof(t_list*))) == NULL)
		exit(0);
	*start_b = NULL;
	while (get_next_line(0, &line))
	{
		ft_operation(line, start_a, start_b);
		if (!ft_strcmp(argv[1], "-v"))
		{
			ft_putstr("stack a : ");
			print_list(start_a);
			ft_putstr("stack b : ");
			print_list(start_b);
		}
		free(line);
	}
	ft_is_sorted(start_a, start_b);
}

void	ft_operation(char *line, t_list **start_a, t_list **start_b)
{
	if (!strcmp(line, "sa") || !strcmp(line, "sb") || !strcmp(line, "ss"))
		ft_swap_elem(line, start_a, start_b);
	else if (!strcmp(line, "ra") || !strcmp(line, "rb") || !strcmp(line, "rr"))
		ft_rotate_elem(line, start_a, start_b);
	else if (!strcmp(line, "rra") || !strcmp(line, "rrb") ||
		!strcmp(line, "rrr"))
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
