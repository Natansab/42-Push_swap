/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:12:07 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/26 11:16:29 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
// #include "checker.h"
#include <stdlib.h>
#include <stdio.h>

// Read the argv input
// Get the operations
// Each time operator is read, modifie the stack

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

// TEST Impresions de la liste
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
		// printf("hello2\n");

		printf("%i ", *((int*)(tmp)->content));
		// printf("element %i, prev is%p, tmp is%p and next is%p\n", i, (tmp)->previous, tmp, (tmp)->next);
		tmp = tmp->next;
		i++;
	}
	printf("%i\n", *((int*)(tmp)->content));
	// printf("element %i, prev is%p, tmp is%p and next is%p\n", i, (tmp)->previous, tmp, (tmp)->next);
	// printf("\n*start_a vaut %i\n", *((int*)(*start_a)->content));
	//printf("*end_a vaut %i\n", *((int*)(*end_a)->content));
	// TEST Impressions
}

void ft_swap_elem(char *line, t_list **start_a, t_list **start_b)
{
	int pivot;

	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss"))
	{
		pivot = *((int*)(*start_a)->content);
		*((int*)(*start_a)->content) = *((int*)((*start_a)->next)->content);
		*((int*)((*start_a)->next)->content) = pivot;
	}

	if (!ft_strcmp(line, "sb") || !ft_strcmp(line, "ss"))
	{
		pivot = *((int*)(*start_b)->content);
		*((int*)(*start_b)->content) = *((int*)((*start_b)->next)->content);
		*((int*)((*start_b)->next)->content) = pivot;
	}
}

void	ft_rotate_elem(char *line, t_list **start_a, t_list **start_b)
{
	if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rr"))
		(*start_a) = (*start_a)->next;
	if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
		(*start_b) = (*start_b)->next;
}

void	ft_rev_rotate_elem(char *line, t_list **start_a, t_list **start_b)
{
	if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr"))
		(*start_a) = (*start_a)->previous;
	if (!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
		(*start_b) = (*start_b)->previous;
}

void	ft_push_elem(char *line, t_list **start_a, t_list **start_b)
{
	if (!ft_strcmp(line, "pb"))
	{
		t_list *pivot;
		pivot = (*start_a)->next;
		((*start_a)->previous)->next = (*start_a)->next;
		((*start_a)->next)->previous = (*start_a)->previous;
		// printf("prev->next is %p, start->next is%p\n", ((*start_a)->previous)->next, (*start_a)->next);
		// t_list *pivot;
		// pivot = *start_a;
		if (!*start_b)
		{
			*start_b = *start_a;
			(*start_b)->next = NULL;
			(*start_b)->previous = NULL;
		}
		else
		{
			(*start_a)->previous = (*start_b)->previous;
			(*start_a)->next = (*start_b);
			printf("hello4\n");
			((*start_b)->previous)->next = *start_a;
			printf("hello4\n");
			(*start_b)->previous = *start_a;
			printf("hello4\n");
			*start_b = *start_a;
			printf("hello4\n");
		}
		// printf("prev->next is %p, start->next is%p\n", ((*start_a)->previous)->next, (*start_a)->next);
		// printf("prev->next is %p, start->next is%p\n", ((*start_a)->previous)->next, (*start_a)->next);
		*start_a = pivot;
		// printf("pivot is %p\n", pivot);
		// printf("prev->next is %p, start->next is%p\n", ((*start_a)->previous)->next, (*start_a)->next);
		// printf("hello4\n");
	}
}

void	ft_operation(char *line, t_list **start_a, t_list **start_b)
{
	ft_swap_elem(line, start_a, start_b);
	ft_rotate_elem(line, start_a, start_b);
	ft_rev_rotate_elem(line, start_a, start_b);
	ft_push_elem(line, start_a, start_b);
}

int		main(int argc, char **argv)
{
	t_list **start_a;
	t_list **start_b;
	int		*value;
	int		i;
	char **line;
	int ret;

	start_b = malloc(sizeof(t_list*));
	*start_b = NULL;
	value = malloc(4);
	start_a = malloc(sizeof(t_list*));
	*value = ft_atoi(argv[argc - 1]);
	*start_a = ft_lstnew(value, 4);
	i = 2;
	while (i < argc)
	{
		*value = ft_atoi(argv[argc - i]);
		ft_lstadd(start_a, ft_lstnew(value , 4));
		i++;
	}

	linear_to_circular_lst(*start_a);
	print_list(start_a);

	line = malloc(sizeof(char*));
	*line = malloc(5);
	ret = 1;
	while(ret != 0)
	{
		// On lit entrees
		ret = get_next_line(0, line);
		ft_operation(line[0], start_a, start_b);
		printf("stack a : \n");
		if (*start_a)
			print_list(start_a);
		printf("stack b : \n");
		if (*start_b)
			print_list(start_b);

	}
return (0);
}
