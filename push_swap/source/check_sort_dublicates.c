/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_dublicates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:23:59 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 15:44:00 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_sort(t_mass *mass)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i != mass->argc - 1)
	{
		if (mass->dest[i] < mass->dest[i + 1])
			;
		else if (mass->dest[i] > mass->dest[i + 1] && mass->argc - 1 != i)
			flag = 1;
		i++;
	}
	return (flag);
}
