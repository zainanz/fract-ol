/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:31:04 by zali              #+#    #+#             */
/*   Updated: 2025/05/21 13:48:32 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	bytes_written;

	bytes_written = 0;
	if (!str || !fd)
		return ;
	while (*str)
	{
		bytes_written = write(fd, str, 1);
		if (bytes_written == 0)
			return ;
		str++;
	}
}

int	valid_num(char *str)
{
	int	decimal_counts;

	decimal_counts = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if ((*(str - 1) == '-' || *(str - 1) == '+') && (*str == ' '
			|| *str == '\0'))
		return (0);
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || (*str == '.' && !decimal_counts)))
			return (0);
		if (*str == '.')
			decimal_counts++;
		str++;
	}
	return (1);
}

double	ft_extract_double(char *str)
{
	int		sign;
	int		int_val;
	double	frac_val;
	double	div;

	sign = 1;
	div = 1;
	int_val = 0;
	frac_val = 0;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9' && *str != '.')
		int_val = (int_val * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		div /= 10;
		frac_val = frac_val + (*str++ - 48) * div;
	}
	return ((int_val + frac_val) * sign);
}
