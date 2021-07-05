/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:17:29 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/05 19:00:13 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove_extension(char *filename)
{
	char	*base_name;
	char	*dot;
	char	*sep;

	if (!filename)
		return (NULL);
	base_name = (char *)malloc(sizeof(char) * ft_strlen(filename) + 1);
	if (!base_name)
		return (NULL);
	ft_strcpy(base_name, filename);
	dot = ft_strrchr(base_name, '.');
	if (ft_strcmp(dot, "."))
	{
		sep = ft_strrchr(base_name, '/');
		if (ft_strcmp(sep, "/"))
		{
			if (sep < dot)
				*dot = '\0';
		}
		else
			*dot = '\0';
	}
	return (base_name);
}
