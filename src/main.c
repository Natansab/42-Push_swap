/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:12:07 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/28 19:32:35 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <checker.h>

void	print_list(t_list **start_a)
{
	int		i;
	t_list	*tmp;

	if (!*start_a)
		return ;
	tmp = *start_a;
	i = 0;
	while (tmp->next != *start_a && tmp->next)
	{
		printf("%i ", *((int*)(tmp)->content));
		tmp = tmp->next;
		i++;
	}
	printf("%i \n", *((int*)(tmp)->content));
}

void	ft_exit_free_a(t_list *start_a)
{
	ft_putstr_fd("Error\n", 2);
	(void)start_a;
	// free_lst(start_a);
	exit (0);
}
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

size_t		increment_j(int argc, char **argv, int i, size_t j)
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

t_list		*get_figures(int argc, char **argv)
{
	int	value;
	int	i;
	size_t j;
	t_list *start_a;

	i = 0;
	start_a = NULL;
	while (i++ < argc - 1)
		if (!ft_digit_or_space(argv[i]))
		{
			ft_putstr_fd("Erreur\n", 2);
			exit(0);
		}
	i = 1;
	j = 1;
	while (i < argc)
	{
		j = increment_j(argc, argv, i, j);
		value = ft_atoi(&argv[argc - i][ft_strlen(argv[argc - i]) - j + 1]);
		if (start_a == NULL)
			start_a = ft_lstnew(&value, sizeof(int));
		else
			ft_lstadd(&start_a, ft_lstnew(&value, 4));
		ft_is_elem_dup(start_a);
		if (ft_strlen(argv[argc - i]) - j + 1 == 0 && i++)
			j = 1;
	}
	return (start_a);
}

int		main(int argc, char **argv)
{
	t_list	*start_a;

	start_a = get_figures(argc, argv);
	linear_to_circular_lst(start_a);
	print_list(&start_a);
	read_ope(&start_a);
	return (0);
}
