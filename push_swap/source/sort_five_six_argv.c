/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_six_argv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:50:58 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 14:13:53 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_five_list_mix(t_stack **list_a, t_stack **list_b)
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
	sort_four_argv_min(list_a, list_b);
	list_pp(list_b, list_a, 0);
}

int	max_min_stack(t_stack *list_b)
{
	int		minmax;
	t_stack	*dest;

	dest = list_b;
	minmax = -2147483648;
	while (dest)
	{
		if (minmax < dest->count)
			minmax = dest->count;
		dest = dest->next;
	}
	return (minmax);
}

void	sort_five_list_max(t_stack **list_a, t_stack **list_b)
{
	int	max;

	max = max_min_stack(*list_b);
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
	sort_four_argv_max(list_a, list_b);
}

void	sort_six_list_mix(t_stack **list_a, t_stack **list_b)
{
	int		min;

	min = max_min_stack(*list_b);
	while (list_a)
	{
		if ((*list_a)->count == min)
		{
			list_pp(list_a, list_b, 1);
			break ;
		}
		list_rrab(list_a, 1);
	}
	sort_five_list_mix(list_a, list_b);
	list_pp(list_b, list_a, 0);
}

void	sort_six_list_max(t_stack **list_a, t_stack **list_b)
{
	int		max;

	max = max_min_stack(*list_b);
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
	sort_five_list_max(list_a, list_b);
}
