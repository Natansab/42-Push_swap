/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:13:07 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/26 20:49:16 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <string.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

void	ft_push_elem(t_list **start_a, t_list **start_b);
void	ft_swap_elem(char *line, t_list **start_a, t_list **start_b);
void	ft_rotate_elem(char *line, t_list **start_a, t_list **start_b);
void	ft_rev_rotate_elem(char *line, t_list **start_a, t_list **start_b);
int		nb_of_elem(t_list *begin_lst);
void	linear_to_circular_lst(t_list *begin_lst);
int		nb_of_elem(t_list *begin_lst);
void	read_ope(t_list **start_a, t_list **start_b);
void	print_list(t_list **start_a);
void	ft_operation(char *line, t_list **start_a, t_list **start_b);
void	ft_operation(char *line, t_list **start_a, t_list **start_b);

#endif
