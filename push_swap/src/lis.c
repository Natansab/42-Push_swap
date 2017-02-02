/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:27:02 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/01 16:21:47 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

/* lis() returns the length of the longest increasing
  subsequence in arr[] of size n */
int lis(t_list *start_a)
{
    int	*lis;
	int	i;
	int	j;
	int	max;
	t_list *start_ai;
	t_list *start_aj;

	max = 0;
    lis = (int*)malloc(sizeof(int) * nb_of_elem(start_a));

    /* Initialize LIS values for all indexes */
    // for (i = 0; i < n; i++ )
    //     lis[i] = 1;
	i = 0;
	while (i < nb_of_elem(start_a))
	{
		lis[i] = 1;
		i++;
	}

    /* Compute optimized LIS values in bottom up manner */
	i = 1;
	start_ai = start_a->next;
	while(start_ai->next != start_a)
	{
		j = 0;
		start_aj = start_a;
		while (j < i)
		{
			if (*((int*)start_ai->content) > *((int*)start_aj->content) && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			start_aj = start_aj->next;
			j++;
		}
		start_ai = start_ai->next;
		i++;
	}
	start_aj = start_a;
	j = 0;
	while (j < i)
	{
		if (*((int*)start_ai->content) > *((int*)start_aj->content) && lis[i] < lis[j] + 1)
			lis[i] = lis[j] + 1;
		start_aj = start_aj->next;
		j++;
	}

    // for (i = 1; i < n; i++)
    //     for (j = 0; j < i; j++ )
    //         if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
    //             lis[i] = lis[j] + 1;

    /* Pick maximum of all LIS values */
    for (i = 0; i < nb_of_elem(start_a); i++ )
        if (max < lis[i])
            max = lis[i];

    /* Free memory to avoid memory leak */
    free(lis);

    return max;
}
