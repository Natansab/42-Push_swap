/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:12:07 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/27 17:19:38 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <checker.h>

void	print_list(t_list **start_a)
{
	int i;
	t_list *tmp;

	if (!*start_a)
		return ;
	tmp = *start_a;
	i = 0;
	while (tmp->next != *start_a && tmp->next)
	{
		printf("%i ", *((int*)(tmp)->content));
		// printf("element %i, prev is%p, tmp is%p and next is%p\n", i, (tmp)->previous, tmp, (tmp)->next);
		tmp = tmp->next;
		i++;
	}
	printf("%i \n", *((int*)(tmp)->content));
	// printf("element %i, prev is%p, tmp is%p and next is%p\n", i, (tmp)->previous, tmp, (tmp)->next);
}

void	ft_exit_free_a(t_list *start_a)
{
	ft_putstr("Erreur\n");
	free_lst(start_a);
	exit (0);
}
void	ft_is_elem_dup(t_list *stack_a)
{
	t_list *tmp;

	if (!stack_a->next)
		return ;
	tmp = stack_a->next;
	while (tmp)
	{
		if (*((int*)tmp->content) == (*(int*)stack_a->content))
			ft_exit_free_a(stack_a);
		tmp = tmp->next;
	}
}

void	get_figures(int argc, char **argv, t_list **start_a)
{
	int	value;
	int	i;

	i = 0;
	while (i++ < argc - 1)
		if (!ft_digit_or_space(argv[i]))
			ft_exit_free_a(*start_a);
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[argc - i]);
		if (*start_a == NULL)
			*start_a = ft_lstnew(&value, sizeof(int));
		else
			ft_lstadd(start_a, ft_lstnew(&value , 4));
		ft_is_elem_dup(*start_a);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_list	**start_a;
	t_list	**start_b;

	start_a = malloc(sizeof(t_list*));
	*start_a = NULL;
	get_figures(argc, argv, start_a);
	linear_to_circular_lst(*start_a);
	print_list(start_a);
	start_b = malloc(sizeof(t_list*));
	*start_b = NULL;
	read_ope(start_a, start_b);
return (0);
}
