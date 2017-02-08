/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:12:07 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 20:31:15 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

void	ft_is_elem_dup(t_list *stack_a)
{
	t_list *tmp;

	if (!stack_a->next)
		return ;
	tmp = stack_a->next;
	while (tmp)
	{
		if (*((int*)tmp->content) == (*(int*)stack_a->content))
			ft_exit_free_a(stack_a);
		tmp = tmp->next;
	}
}

size_t	increment_j(int argc, char **argv, int i, size_t j)
{
	size_t h;

	h = ft_strlen(argv[argc - i]);
	while (argv[argc - i][h - j] && argv[argc - i][h - j] == ' ')
		j++;
	while (argv[argc - i][h - j] && ft_isdigit(argv[argc - i][h - j]))
		j++;
	if (argv[argc - i][h - j] == '-')
		j++;
	while (argv[argc - i][h - j] && argv[argc - i][h - j] == ' ')
		j++;
	return (j);
}

void	get_figures_two(int argc, char **argv)
{
	int i;

	if (argc == 1)
		exit(0);
	i = (!ft_strcmp(argv[1], "-v")) ? 1 : 0;
	while (i++ < argc - 1)
		if (!ft_digit_or_space(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
}

t_list	*get_figures(int argc, char **argv)
{
	long int	value;
	int			i;
	size_t		j;
	t_list		*start_a;

	start_a = NULL;
	get_figures_two(argc, argv);
	i = 1;
	j = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[1], "-v") && (argc - i == 1))
			break ;
		j = increment_j(argc, argv, i, j);
		value = ft_atoi(&argv[argc - i][ft_strlen(argv[argc - i]) - j + 1]);
		if (value > INT_MAX || value < INT_MIN)
			ft_exit_free_a(start_a);
		if (start_a == NULL)
			start_a = ft_lstnew(&value, sizeof(int));
		else
			ft_lstadd(&start_a, ft_lstnew(&value, 4));
		ft_is_elem_dup(start_a);
		j = (ft_strlen(argv[argc - i]) - j + 1 == 0 && i++) ? 1 : j;
	}
	return (start_a);
}

int		main(int argc, char **argv)
{
	int		median;
	t_list	*start_a;
	char	*opsresult;

	start_a = get_figures(argc, argv);
	median = find_med_lst(start_a);
	linear_to_circular_lst(start_a);
	if (!(opsresult = malloc((500 + nb_of_elem(start_a)) * 4 * 10)))
		return (0);
	*opsresult = '\0';
	if (is_first_a_sorted(start_a))
	{
		free_lst(start_a);
		return (0);
	}
	else if (nb_of_elem(start_a) <= 5)
		ft_small_algo(start_a, opsresult);
	else
		ft_main_algo(start_a, opsresult);
	ft_optimize_ops(opsresult);
	ft_putstr(opsresult);
	free_lst(start_a);
	free(opsresult);
	return (0);
}
