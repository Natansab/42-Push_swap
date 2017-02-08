/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_med_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:29:42 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 17:04:25 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_med_lst(t_list *start_a)
{
	t_env	p;

	ft_bzero(&p, sizeof(p));
	p.tmp = start_a;
	while (p.tmp)
	{
		p.median = (*(int*)p.tmp->content);
		p.tmp2 = start_a;
		p.sup = 0;
		p.inf = 0;
		while (p.tmp2)
		{
			p.sup = (p.median >= (*(int*)p.tmp2->content)) ? p.sup + 1 : p.sup;
			p.inf = (p.median <= (*(int*)p.tmp2->content)) ? p.inf + 1 : p.inf;
			if (!p.tmp2->next && (p.sup == p.inf || p.sup == p.inf - 1 ||
					p.sup == p.inf + 1))
				return (p.median);
			p.tmp2 = p.tmp2->next;
		}
		p.tmp = p.tmp->next;
	}
	return (p.median);
}

int	find_med_lst2(t_list *start_a, int length)
{
	t_env	p;

	ft_bzero(&p, sizeof(p));
	p.tmp = start_a;
	while (p.i < length)
	{
		p.median = (*(int*)p.tmp->content);
		p.tmp2 = start_a;
		p.sup = 0;
		p.inf = 0;
		p.j = -1;
		while (p.j++ < length)
		{
			p.sup = (p.median > (*(int*)p.tmp2->content)) ? p.sup + 1 : p.sup;
			p.inf = (p.median < (*(int*)p.tmp2->content)) ? p.inf + 1 : p.inf;
			if (p.j == (length - 1) && (((p.sup == p.inf + 1) &&
				!(length % 2)) || ((p.sup == p.inf) && (length % 2))))
				return (p.median);
			p.tmp2 = p.tmp2->next;
		}
		p.tmp = p.tmp->next;
		p.i++;
	}
	return (p.median);
}
