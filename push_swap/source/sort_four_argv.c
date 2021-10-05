/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:51:30 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 14:22:14 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_four_argv_min(t_stack **list_a, t_stack **list_b)
{
	int		min;
	t_stack	*dest;

	min = 2147483647;
	dest = *list_a;
	while (dest)
	{
		if (min > dest->count)
			min = dest->count;
		dest = dest->next;
	}
	while (list_a)
	{
		if ((*list_a)->count == min)
		{
			list_pp(list_a, list_b, 1);
			break ;
		}
		list_rrab(list_a, 1);
	}
	sort_three_argv_min(list_a);
	list_pp(list_b, list_a, 0);
}

void	sort_four_argv_max(t_stack **list_a, t_stack **list_b)
{
	int		max;

	max = max_min_stack(*list_b);
	ft_check_max(list_a, list_b, max);
	sort_three_argv_max(list_a, list_b);
}

void	ft_check_max(t_stack **list_a, t_stack **list_b, int max)
{
	while (list_b)
	{
		if ((*list_b)->count == max)
		{
			list_pp(list_b, list_a, 0);
			(*list_a)->divs = -1;
			break ;
		}
		list_rrab_stack_b(list_b, max);
	}
}
