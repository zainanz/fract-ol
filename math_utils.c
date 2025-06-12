/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:02:04 by zali              #+#    #+#             */
/*   Updated: 2025/05/21 18:26:23 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_scale_value(double unscaled_num, double new_min, double new_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (HEIGHT - 0) + new_min);
}
