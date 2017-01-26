/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:12:07 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/26 21:23:31 by nsabbah          ###   ########.fr       */
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

// Gerer le EOF => ne pas recup ft_atoi directement
// void	ft_is_sorted(t_list **start_a, t_list **start_b)
// {
// 	// t_list *tmp;
// 	int		error;
//
// 	error = 0;
// 	if (*start_b)
// 		error = 1;
// 	if (*start_a && (*start_a)->next &&
// 		(*(int*)(*start_a)->content) > (*(int*)((*start_a)->next)->content))
// 		error = 1;
// 	if (error)
// 		ft_putstr("KO\n");
// 	else
// 		ft_putstr("OK\n");
// }

void	ft_is_elem_dup(t_list *stack_a)
{
	t_list *tmp;

	if (!stack_a->next)
		return ;
	tmp = stack_a->next;
	while (tmp)
	{
		if (*((int*)tmp->content) == (*(int*)stack_a->content))
		{
			printf("Erreur\n");
			exit (0);
		}
		tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
	t_list	**start_a;
	t_list	**start_b;
	int		*value;
	int		i;

	start_b = malloc(sizeof(t_list*));
	*start_b = NULL;
	value = malloc(sizeof(int));
	start_a = malloc(sizeof(t_list*));
	*value = ft_atoi(argv[argc - 1]);
	*start_a = ft_lstnew(value, sizeof(int));
	i = 2;
	while (i < argc)
	{
		*value = ft_atoi(argv[argc - i]);
		ft_lstadd(start_a, ft_lstnew(value , 4));
		ft_is_elem_dup(*start_a);
		i++;
	}
	linear_to_circular_lst(*start_a);
	print_list(start_a);
	read_ope(start_a, start_b);
	// ft_is_sorted(start_a, start_b);
return (0);
}
