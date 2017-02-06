/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:23:43 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/06 14:13:41 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rid_of_a(t_list **start_a, t_list **start_b, int median, char *opsresult)
{
	int lot;
	int taille;
	int i = 0;
	int next = 0;

	taille = (*start_a)->lot;
	lot = 0;
	if (taille == 2)
	{
		if ((*(int*)(*start_a)->content) > (*(int*)(*start_a)->next->content))
		{
			ft_do_swap(start_a);
			ft_strcat(opsresult, "sa\n");
		}
		(*start_a)->lot = 1;
		return ;
	}
	while (i < taille)
	{
		if ((*(int*)(*start_a)->content) >= median)
		{
			(*start_a) = (*start_a)->next;
			ft_strcat(opsresult, "ra\n");
			next++;
		}
		else if ((*(int*)(*start_a)->content) < median)
		{
			lot++;
			ft_strcat(opsresult, "pb\n");
			ft_push_elem(start_a, start_b);
			(*start_b)->lot = lot;
		}
		i++;
	}
	while (next)
	{
		(*start_a) = (*start_a)->previous;
		ft_strcat(opsresult, "rra\n");
		next--;

	}
	(*start_a)->lot = taille - lot;
}

void	get_rid_of_b(t_list **start_a, t_list **start_b, int median, char *opsresult)
{
	int		lot;
	int		taille;
	int		i;
	int		next;
	t_list	*tmp;

	next = 0;
	i = 0;
	taille = (*start_b)->lot;
	lot = 0;
	while ((i < taille))
	{
		if ((*(int*)(*start_b)->content) < median)
		{
			(*start_b) = (*start_b)->next;
			ft_strcat(opsresult, "rb\n");
			next++;
		}
		else if ((*(int*)(*start_b)->content) >= median)
		{
			lot++;
			ft_strcat(opsresult, "pa\n");
			ft_push_elem(start_b, start_a);
			(*start_a)->lot = lot;
		}
		i++;
	}
	while (next && *start_b && nb_of_elem(*start_b) != 1)
	{
		(*start_b) = (*start_b)->previous;
		ft_strcat(opsresult, "rrb\n");
		next--;

	}
	if (taille == 1)
		return ;
	tmp = *start_b;
	i = 0;
	while (taille - lot - i && tmp)
	{
		tmp->lot = taille - lot - i;
		tmp = tmp->next;
		i++;
	}
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

void	order_in_place_a(t_list **start_a, char *opsresult)
{
	if (is_first_a_sorted(*start_a))
		return ;
	else if (nb_of_elem(*start_a) == 2)
	{
		ft_do_swap(start_a);
		ft_strcat(opsresult, "sa\n");
	}
	else
	{
		if (*(int*)(*start_a)->content > *(int*)(*start_a)->next->content
				&& *(int*)(*start_a)->content < *(int*)(*start_a)->previous->content)
		{
			ft_do_swap(start_a);
			ft_strcat(opsresult, "sa\n");
		}
		else if (*(int*)(*start_a)->content < *(int*)(*start_a)->next->content
				&& *(int*)(*start_a)->content > *(int*)(*start_a)->previous->content)
		{
			ft_strcat(opsresult, "rra\n");
			ft_do_rev_rotate(start_a);
		}
		else if (*(int*)(*start_a)->content > *(int*)(*start_a)->next->content
				&& *(int*)(*start_a)->content > *(int*)(*start_a)->previous->content)
		{
			if (*(int*)(*start_a)->previous->content > *(int*)(*start_a)->next->content)
			{
				ft_strcat(opsresult, "ra\n");
				ft_do_rotate(start_a);
			}
			else
			{
				ft_strcat(opsresult, "sa\nrra\n");
				ft_do_swap(start_a);
				ft_do_rev_rotate(start_a);
			}
		}
		else if (*(int*)(*start_a)->content < *(int*)(*start_a)->next->content
				&& *(int*)(*start_a)->content < *(int*)(*start_a)->previous->content)
		{
			ft_strcat(opsresult, "ra\nsa\nrra\n");
			ft_do_rotate(start_a);
			ft_do_swap(start_a);
			ft_do_rev_rotate(start_a);
		}
	}
}

void	split_a_first(t_list **start_a, t_list **start_b, int median, char *opsresult)
{
	int		i;
	t_list *tmp;
	int		lot;
	int		tot_a = nb_of_elem(*start_a);
	lot = 0;
	tmp = *start_a;
	i = 0;
	while (i < tot_a)
	{
		if ((*(int*)tmp->content) >= median)
		{
			tmp = tmp->next;
			*start_a = (*start_a)->next;
			ft_strcat(opsresult, "ra\n");
		}
		else if ((*(int*)tmp->content) < median)
		{
			lot++;
			ft_push_elem(start_a, start_b);
			(*start_b)->lot = lot;
			tmp = *start_a;
			ft_strcat(opsresult, "pb\n");
		}
		i++;
	}
}

void	ft_main_algo(t_list *start_a, char *opsresult)
{
	t_list **start_b;
	start_b = malloc(sizeof(t_list*));

	// printf("\n######### Split a first #########\n");
	while (nb_of_elem(start_a) >= 3)
		split_a_first(&start_a, start_b, find_med_lst2(start_a, nb_of_elem(start_a)), opsresult);
	order_in_place_a(&start_a, opsresult);

	// printf("\nstack a vaut : \n");
	// print_list(&start_a);
	// printf("\nstack b vaut : \n");
	// print_list(start_b);

	while (*start_b)
	{
		get_rid_of_b(&start_a, start_b, find_med_lst2(*start_b, (*start_b)->lot), opsresult);

		// printf("\n######### Apres Get rid of b #########\n");
		order_in_place_a(&start_a, opsresult);

		// printf("\nstack a vaut : \n");
		// print_list(&start_a);
		// printf("\nstack b vaut : \n");
		// print_list(start_b);

		// printf("\n######### Apres Get rid of a #########\n");
		while ((start_a)->lot >= 3)
			get_rid_of_a(&start_a, start_b, find_med_lst2(start_a, start_a->lot), opsresult);

		order_in_place_a(&start_a, opsresult);
		// printf("\nstack a vaut : \n");
		// print_list(&start_a);
		// printf("\nstack b vaut : \n");
		// print_list(start_b);


	}
	// printf("\n######### Resultat final #########\n");
	// printf("\nstack a vaut : \n");
	// print_list(&start_a);
	// printf("\nstack b vaut : \n");
	// print_list(start_b);

}
