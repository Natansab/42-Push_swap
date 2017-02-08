/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:28:58 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 20:31:12 by nsabbah          ###   ########.fr       */
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
		if ((tmp = ft_strstr(opsresult, "\nra\nrra"))
				|| (tmp = ft_strstr(opsresult, "\nrra\nra"))
				|| (tmp = ft_strstr(opsresult, "\nrb\nrrb"))
				|| (tmp = ft_strstr(opsresult, "\nrrb\nrb")))
		{
			ft_memmove(tmp, tmp + 7, ft_strlen(tmp + 7) + 1);
			i = 0;
		}
		else if ((tmp = ft_strstr(opsresult, "\npb\npa"))
				|| (tmp = ft_strstr(opsresult, "\npa\npb")))
		{
			ft_memmove(tmp, tmp + 6, ft_strlen(tmp + 6) + 1);
			i = 0;
		}
		else
			i++;
	}
}
