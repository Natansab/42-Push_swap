/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:40:17 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/07 17:48:59 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct	s_min{
	int one;
	int two;
}				t_min;

int		ft_dist(t_list *start_a, int min)
{
	int i;

	i = 0;
	while (i <= nb_of_elem(start_a))
	{
		if (*(int*)start_a->content == min)
			break;
		start_a = start_a->next;
		i++;
	}
	i = (i > 2) ? i - nb_of_elem(start_a) : i;
	return (i);
}

void	move_min_to_b(t_list **start_a, t_list **start_b, int content, char *opsresult)
{
	int distance;

	distance = ft_dist(*start_a, content);
	if (distance > 0)
	{
		while (distance && *start_a && (*start_a)->next)
		{
			*start_a = (*start_a)->next;
			ft_strcat(opsresult, "ra\n");
			distance--;
		}
	}
	else if (distance < 0)
		while (distance && *start_a && (*start_a)->previous)
		{
			*start_a = (*start_a)->previous;
			ft_strcat(opsresult, "rra\n");
			distance++;
		}
	ft_push_elem(start_a, start_b);
	ft_strcat(opsresult, "pb\n");
}

t_min	ft_find_min(t_list *start_a)
{
	int		i;
	t_min	min;
	if (start_a && start_a->next)
	{
		min.one = *(int*)start_a->content;
		min.two = *(int*)start_a->next->content;
	}
	if (min.one > min.two)
	{
		min.two = *(int*)start_a->content;
		min.one = *(int*)start_a->next->content;
	}
	i = 0;
	while (i <= 12)
	{
		if (*(int*)start_a->content <= min.one)
			min.one = *(int*)start_a->content;
		else if (*(int*)start_a->content <= min.two)
			min.two = *(int*)start_a->content;
		start_a = start_a->next;
		i++;
	}
	return (min);
}

void	ft_small_algo(t_list *start_a, char *opsresult)
{
	t_min	min;
	t_list **start_b;

	start_b = malloc(sizeof(t_list*));

	if (nb_of_elem(start_a) <= 2)
		order_in_place_a(&start_a, opsresult);
	else
		{
			min = ft_find_min(start_a);
			if (ft_abs(ft_dist(start_a, min.one)) <= ft_abs(ft_dist(start_a, min.two)) + 1)
			{
				move_min_to_b(&start_a, start_b, min.one, opsresult);
				move_min_to_b(&start_a, start_b, min.two, opsresult);
				order_in_place_a(&start_a, opsresult);
				ft_push_elem(start_b, &start_a);
				ft_push_elem(start_b, &start_a);
				ft_strcat(opsresult, "pa\npa\n");
			}
			else
			{
				move_min_to_b(&start_a, start_b, min.two, opsresult);
				move_min_to_b(&start_a, start_b, min.one, opsresult);
				order_in_place_a(&start_a, opsresult);
				ft_do_swap(start_b);
				ft_push_elem(start_b, &start_a);
				ft_push_elem(start_b, &start_a);
				ft_strcat(opsresult, "sb\npa\npa\n");
			}
		}
}
