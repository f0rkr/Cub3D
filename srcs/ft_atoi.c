/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:53:30 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:53:33 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		condition(long result, int sign)
{
	if (result > 2147483648 && sign == -1)
		return (0);
	if (result > 2147483647 && sign == 1)
		return (-1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long	result;
	int		signe;

	result = 0;
	signe = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
		if ((result > 2147483647 && signe == 1)
				|| (result > 2147483648 && signe == -1))
			return (condition(result, signe));
	}
	return (result * signe);
}
