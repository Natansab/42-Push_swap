/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:28:58 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 17:15:40 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimize_ops(char *opsresult)
{
	int		i;
	char	*tmp;

	i = 0;
	while (opsresult[i])
	{
		if ((tmp = strstr(opsresult, "\nra\nrra"))
				|| (tmp = strstr(opsresult, "\nrra\nra"))
				|| (tmp = strstr(opsresult, "\nrb\nrrb"))
				|| (tmp = strstr(opsresult, "\nrrb\nrb")))
		{
			memmove(tmp, tmp + 7, strlen(tmp + 7) + 1);
			i = 0;
		}
		else if ((tmp = strstr(opsresult, "\npb\npa"))
				|| (tmp = strstr(opsresult, "\npa\npb")))
		{
			memmove(tmp, tmp + 6, strlen(tmp + 6) + 1);
			i = 0;
		}
		else
			i++;
	}
}
