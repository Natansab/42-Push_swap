/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mhza.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:54:13 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/28 17:06:48 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_mhza.h"

static int		ft_failed(char **buffer, char **stock)
{
	ft_strdel(buffer);
	ft_strdel(stock);
	return (READ_ERROR);
}

static int		ft_eof(char **line, char **stock, char **buffer)
{
	if (ft_strlen(*stock))
	{
		if (!(*line = ft_strdup(*stock)))
			return (ft_failed(buffer, stock));
		ft_strdel(stock);
		ft_strdel(buffer);
		return (READ_LINE);
	}
	return (READ_END);
}

unsigned int	ft_strchri(char *stock, char c)
{
	if (ft_strchr(stock, c) != NULL)
		return ((ft_strchr(stock, c) - stock));
	return (READ_ERROR);
}

static int		ft_set_stk(char *tmp, char **stk, char **buffer)
{
	ft_strdel(stk);
	if (!(*stk = ft_strdup(tmp)))
		return (ft_failed(buffer, stk));
	ft_strdel(&tmp);
	return (READ_LINE);
}

int				get_next_line_mhza(const int fd, char **line)
{
	static char		*stk = NULL;
	char			*buffer;
	int				ret;
	char			*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 10000000)
		return (READ_ERROR);
	stk = (!stk) ? ft_strnew(BUFF_SIZE) : stk;
	while (!(ft_strchr(stk, '\n')))
	{
		buffer = ft_strnew(BUFF_SIZE);
		if (!(ret = read(fd, buffer, BUFF_SIZE)))
			return (ft_eof(line, &stk, &buffer));
		if (ret == -1 || !stk || !(tmp = ft_strjoin(stk, buffer)) ||
		ft_set_stk(tmp, &stk, &buffer) == -1)
			return (ft_failed(&buffer, &stk));
		ft_strdel(&buffer);
	}
	if (!(*line = ft_strsub(stk, 0, ft_strchri(stk, '\n'))))
		return (ft_failed(&buffer, &stk));
	if (!(tmp = ft_strsub(stk, ft_strchri(stk, '\n') + 1, ft_strlen(stk))) ||
	ft_set_stk(tmp, &stk, &buffer) == -1)
		return (ft_failed(&buffer, &stk));
	return (READ_LINE);
}
