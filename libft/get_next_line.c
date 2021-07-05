/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:13:34 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/05 19:53:46 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	gnl_check_stock(char **stock, char **line)
{
	char			*tmp;

	tmp = ft_strchr(*stock, '\n');
	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int	gnl_check_read(char *buffer, char **stock, char **line)
{
	char			*tmp;

	tmp = ft_strchr(buffer, '\n');
	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		free(buffer);
		return (1);
	}
	return (0);
}

void	delete_buffer(char *buffer, int n)
{
	if (n == 1)
	{
		free(buffer);
		buffer = NULL;
	}
	else
	{
		free(buffer);
		buffer = NULL;
	}
}

int	get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	char			*buffer;
	int				ret;

	if (stock)
		if (gnl_check_stock(&stock, line))
			return (1);
	buffer = ft_strnew(BUFFER_SIZE);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (gnl_check_read(buffer, &stock, line))
			return (1);
		stock = ft_strjoin(stock, buffer);
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	delete_buffer(buffer, 1);
	if (ret == -1)
		return (-1);
	if (stock == NULL)
		return (0);
	*line = ft_strdup(stock);
	delete_buffer(stock, 2);
	return (1);
}
