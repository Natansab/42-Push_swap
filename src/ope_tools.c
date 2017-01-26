/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:46:19 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/26 21:11:25 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_ope(t_list **start_a, t_list **start_b)
{
	char	**line;
	int		ret;

	line = malloc(sizeof(char*));
	*line = malloc(5);
	ret = 1;
	while(ret != 0)
	{
		ret = get_next_line(0, line);
		ft_operation(line[0], start_a, start_b);
		printf("stack a : ");
		if (*start_a)
			print_list(start_a);
		printf("stack b : ");
		if (*start_b)
			print_list(start_b);
		printf("\n");
	}
	free(line);
}

void	ft_operation(char *line, t_list **start_a, t_list **start_b)
{
	printf("line %s\n", line);
	if (!strcmp(line, "sa") || !strcmp(line, "sb") || !strcmp(line, "ss"))
		ft_swap_elem(line, start_a, start_b);
	else if (!strcmp(line, "ra") || !strcmp(line, "rb") || !strcmp(line, "rr"))
		ft_rotate_elem(line, start_a, start_b);
	else if (!strcmp(line, "rra") || !strcmp(line, "rrb") || !strcmp(line, "rrr"))
		ft_rev_rotate_elem(line, start_a, start_b);
	else if (!ft_strcmp(line, "pb") && *start_a)
		ft_push_elem(start_a, start_b);
	else if (!ft_strcmp(line, "pa") && *start_b)
		ft_push_elem(start_b, start_a);
	else if (ft_strcmp(line, "pa") && ft_strcmp(line, "pb"))
		{
			printf("Erreeeeeur\n");
			exit (0);
		}
}
