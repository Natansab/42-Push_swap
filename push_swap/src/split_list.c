/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:23:43 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/02 19:14:50 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_list_inner(t_list **start_a, t_list *start_b, int median, int tot_a, int tot_b)
{
	int		i;
	t_list *tmp;

	tmp = *start_a;
	i = 0;
	// printf("tot_a vaut %i\n", tot_a);
	while (i < tot_a)
	{
		if ((*(int*)tmp->content) >= median)
		{
			tmp = tmp->next;
			*start_a = (*start_a)->next;
			printf("ra\n");
		}
		else if ((*(int*)tmp->content) < median)
		{
			ft_push_elem(start_a, &start_b);
			tmp = *start_a;
			tot_b++;
			printf("pb\n");
		}
		i++;
	}
}

void	split_list(t_list *start_a, int median, int tot_a, int tot_b)
{
	int		i;
	t_list **start_b;
	t_list *tmp;

	start_b = malloc(sizeof(t_list*));
	tmp = start_a;
	i = 0;
	while (i < tot_a)
	{
		// printf("tmp->content vaut %i\n", (*(int*)tmp->content));
		// printf("median vaut %i\n", median);
		if ((*(int*)tmp->content) >= median)
		{
			tmp = tmp->next;
			start_a = start_a->next;
			printf("ra\n");
		}
		else if ((*(int*)tmp->content) < median)
		{
			ft_push_elem(&start_a, start_b);
			tmp = start_a;
			printf("pb\n");
			tot_b++;
		}
		i++;
	}
	tot_a = tot_a - tot_b;
// printf("\nstack a vaut : \n");
// print_list(&start_a);
// printf("\nstack b vaut : \n");
// print_list(start_b);
// printf("\n\n");

// printf("total a vaut %i\n", tot_a);
// printf("median2 vaut  %i\n", find_med_lst2(start_a, tot_a));
printf("######### Rappel de la fonction split #########\n");
while (nb_of_elem(start_a) > 3)
	{
		// printf("tot_a vaut %i\n", tot_a);
		// printf("nb_of_elem(start_a) vaut %i\n", nb_of_elem(start_a));
		split_list_inner(&start_a, *start_b, find_med_lst2(start_a, nb_of_elem(start_a)), nb_of_elem(start_a), tot_b);
		// printf("\nstack a vaut : \n");
		// print_list(&start_a);
		// printf("\nstack b vaut : \n");
		// print_list(start_b);
	}
			printf("\nstack a vaut : \n");
			print_list(&start_a);
			printf("\nstack b vaut : \n");
			print_list(start_b);
}
