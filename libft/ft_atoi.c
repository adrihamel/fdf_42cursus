/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:17:57 by aguerrer          #+#    #+#             */
/*   Updated: 2021/05/24 20:08:42 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int			sign;
	long long	n;

	sign = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str != '+' && *str != '-' && ft_isdigit((int)*str) == 0)
		return (0);
	if (*str == '-')
		sign = -1;
	if (ft_isdigit((int)*str) == 0)
		str++;
	if (ft_isdigit((int)*str) == 0)
		return (0);
	while (ft_isdigit((int)*str))
	{
		n = n * 10 + *str++ - '0';
		if ((n * sign) > INT_MAX)
			return (-1);
		if ((n * sign) < INT_MIN)
			return (0);
	}
	return (n * sign);
}
