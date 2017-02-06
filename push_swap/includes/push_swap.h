/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:13:07 by ewallner          #+#    #+#             */
/*   Updated: 2017/02/06 14:29:07 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

void	ft_push_elem(t_list **start_a, t_list **start_b);
void	ft_swap_elem(char *line, t_list **start_a, t_list **start_b);
void	ft_rotate_elem(char *line, t_list **start_a, t_list **start_b);
void	ft_rev_rotate_elem(char *line, t_list **start_a, t_list **start_b);
int		nb_of_elem(t_list *begin_lst);
void	linear_to_circular_lst(t_list *begin_lst);
int		nb_of_elem(t_list *begin_lst);
void	read_ope(t_list **start_a, char **argv);
void	print_list(t_list **start_a);
void	ft_operation(char *line, t_list **start_a, t_list **start_b);
void	ft_operation(char *line, t_list **start_a, t_list **start_b);
int		ft_digit_or_space(char *str);
void	free_lst(t_list *lst);
void	ft_exit_free_a(t_list *lst);
void	ft_exit_free_a(t_list *start_a);
int		lis(t_list *start_a);
int		find_med_lst(t_list *start_a);
int		find_med_lst2(t_list *start_a, int lenghth);
void	ft_do_swap(t_list **stack);
void	ft_do_psuh(t_list **src_pile, t_list **dst_pile);
void	ft_do_rotate(t_list **stack);
void	ft_do_rev_rotate(t_list **stack);
void	order_in_place_a(t_list **start_a, char *opsresult);
void	ft_main_algo(t_list *start_a, char *opsresult);
void	ft_optimize_ops(char *opsresult);
#endif
