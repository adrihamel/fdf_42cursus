/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:16:22 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/05 19:26:27 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(const char *str, char c)
{
	int		len;
	char	*cut;

	len = 0;
	while (str[len] != c && str[len])
		if (str[len++] == c)
			break ;
	cut = (char *)malloc(sizeof(char) * len + 1);
	if (!cut)
		return (NULL);
	ft_strncpy(cut, str, len);
	cut[len + 1] = '\0';
	return (cut);
}
