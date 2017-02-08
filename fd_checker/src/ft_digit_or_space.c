/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_or_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:19:20 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/30 18:35:37 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ctype.h"

int	ft_digit_or_space(char *str)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (*str)
	{
		if (!ft_strchr(" -0123456789", *str))
			return (0);
		if (*str == ' ')
			i++;
		if (*str == '-' && (!ft_strchr("0123456789", str[1]) || !str[1]))
			return (0);
		str++;
	}
	if (i == ft_strlen(tmp))
		return (0);
	return (1);
}
