/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:23:43 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/03 17:29:56 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rid_of_a(t_list **start_a, t_list **start_b, int median)
{
	int lot;
	int taille;
	int i = 0;
	int next = 0;

	taille = (*start_a)->lot;
	lot = 0;
	while (i < taille)
	{
		if ((*(int*)(*start_a)->content) < median)
		{
			(*start_a) = (*start_a)->next;
			next++;
		}
		else if ((*(int*)(*start_a)->content) >= median)
		{
			lot++;
			// printf("\nstack b vaut : \n");
			// print_list(start_b);
			// printf("\n\n");
			ft_push_elem(start_a, start_b);
			(*start_b)->lot = lot;
		}
	i++;
	}
	while (next)
	{
		(*start_a) = (*start_a)->previous;
		next--;

	}
	(*start_a)->lot = (*start_a)->lot - lot;
}




void	get_rid_of_b(t_list **start_a, t_list **start_b, int median)
{
	int lot;
	int taille;
	int i = 0;
	int next = 0;

	taille = (*start_b)->lot;
	lot = 0;
	while (i < taille)
	{
		if ((*(int*)(*start_b)->content) < median)
		{
			(*start_b) = (*start_b)->next;
			next++;
		}
		else if ((*(int*)(*start_b)->content) >= median)
		{
			lot++;
			// printf("\nstack b vaut : \n");
			// print_list(start_b);
			// printf("\n\n");
			ft_push_elem(start_b, start_a);
			(*start_a)->lot = lot;
		}
	i++;
	}
	while (next)
	{
		(*start_b) = (*start_b)->previous;
		next--;

	}
	(*start_b)->lot = (*start_b)->lot - lot;
}

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

void	order_in_place_a(t_list **start_a)
{
	if (is_first_a_sorted(*start_a))
		return ;
	else if (nb_of_elem(*start_a) == 2)
		ft_do_swap(start_a);
	else
	{
		if (*(int*)(*start_a)->content > *(int*)(*start_a)->next->content
		&& *(int*)(*start_a)->content < *(int*)(*start_a)->previous->content)
			ft_do_swap(start_a);
		else if (*(int*)(*start_a)->content < *(int*)(*start_a)->next->content
		&& *(int*)(*start_a)->content > *(int*)(*start_a)->previous->content)
			ft_do_rev_rotate(start_a);
		else if (*(int*)(*start_a)->content > *(int*)(*start_a)->next->content
		&& *(int*)(*start_a)->content > *(int*)(*start_a)->previous->content)
		{
			if (*(int*)(*start_a)->previous->content > *(int*)(*start_a)->next->content)
				ft_do_rotate(start_a);
		 	else
			{
				ft_do_swap(start_a);
				ft_do_rev_rotate(start_a);
			}
		}
		else if (*(int*)(*start_a)->content < *(int*)(*start_a)->next->content
		&& *(int*)(*start_a)->content < *(int*)(*start_a)->previous->content)
		{
			ft_do_rotate(start_a);
			ft_do_swap(start_a);
			ft_do_rev_rotate(start_a);
		}
	}
}

void	split_list_inner(t_list **start_a, t_list **start_b, int median, int tot_a, int tot_b)
{
	int		i;
	t_list *tmp;
	int		lot;

	lot = 0;
	tmp = *start_a;
	i = 0;
	while (i < tot_a)
	{
		if ((*(int*)tmp->content) >= median)
		{
			tmp = tmp->next;
			*start_a = (*start_a)->next;
			// printf("ra\n");
		}
		else if ((*(int*)tmp->content) < median)
		{
			lot++;
			// printf("\nstack b vaut : \n");
			// print_list(start_b);
			// printf("\n\n");
			ft_push_elem(start_a, start_b);
			(*start_b)->lot = lot;
			tmp = *start_a;
			tot_b++;
			// printf("pb\n");
		}
		// printf("i vaut %i et tot_a vaut %i\n", i, tot_a);
		i++;
	}
}

void	split_list(t_list *start_a, int median, int tot_a, int tot_b)
{
	int		i;
	t_list **start_b;
	t_list *tmp;
	int		lot = 0;

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
			// printf("ra\n");
		}
		else if ((*(int*)tmp->content) < median)
		{
			lot++;
			// printf("\nstack b vaut : \n");
			// print_list(start_b);
			// printf("\n\n");
			ft_push_elem(&start_a, start_b);
			(*start_b)->lot = lot;
			tmp = start_a;
			// printf("pb\n");
			tot_b++;
		}
		i++;
	}
	tot_a = tot_a - tot_b;

printf("\n\n######### Appel de la fonction 1 de Split #########\n");
printf("\nstack a vaut : \n");
print_list(&start_a);
printf("\nstack b vaut : \n");
print_list(start_b);
printf("\n\n");

int ctr = 0;
// printf("total a vaut %i\n", tot_a);
// printf("median2 vaut  %i\n", find_med_lst2(start_a, tot_a));
// printf("######### Rappel de la fonction split #########\n");
while (((nb_of_elem(start_a) > 3) && ((nb_of_elem(start_a) + nb_of_elem(*start_b)) % 2)) ||
  		((nb_of_elem(start_a) >= 3) && !((nb_of_elem(start_a) + nb_of_elem(*start_b)) % 2)))
	{
		printf("\n\n######### Rappel %i de la fonction split  #########\n", ctr);
		// printf("nb_of_elem(start_a) vaut %i\n", nb_of_elem(start_a));
		// printf("tot_a vaut %i\n", tot_a);
		// printf("nb_of_elem(start_a) vaut %i\n", nb_of_elem(start_a));
		split_list_inner(&start_a, start_b, find_med_lst2(start_a, nb_of_elem(start_a)), nb_of_elem(start_a), tot_b);
		printf("\nstack a vaut : \n");
		print_list(&start_a);
		printf("\nstack b vaut : \n");
		print_list(start_b);
		printf("\nstack a vaut : \n");
		print_list(&start_a);
		printf("\nstack b vaut : \n");
		print_list(start_b);
		ctr++;
	}
//
printf("\n######### Apres tri de a #########\n");

			order_in_place_a(&start_a);

			printf("\nstack a vaut : \n");
			print_list(&start_a);
			printf("\nstack b vaut : \n");
			print_list(start_b);


 while (*start_b)
 {
	// printf("\n\nmedian vaut %i\n", find_med_lst2(*start_b, (*start_b)->lot));
	get_rid_of_b(&start_a, start_b, find_med_lst2(*start_b, (*start_b)->lot));

	printf("\n######### Apres Get rid of b #########\n");
			order_in_place_a(&start_a);

			printf("\nstack a vaut : \n");
			print_list(&start_a);
			printf("\nstack b vaut : \n");
			print_list(start_b);


	while ((start_a)->lot >= 2)
		get_rid_of_a(&start_a, start_b, find_med_lst2(start_a, start_a->lot));

	printf("\n######### Apres Get rid of a #########\n");
			order_in_place_a(&start_a);

			printf("\nstack a vaut : \n");
			print_list(&start_a);
			printf("\nstack b vaut : \n");
			print_list(start_b);


}

}
