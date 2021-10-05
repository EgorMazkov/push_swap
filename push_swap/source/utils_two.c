/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:13:30 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 12:13:31 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*last_list(t_stack **list_a)
{
	if (*(list_a))
	{
		while ((*list_a)->next)
			(*list_a) = (*list_a)->next;
		return (*list_a);
	}
	return (*list_a);
}

int	check_divs_distance(t_stack **list_a)
{
	int		i;
	t_stack	**list_divs;

	list_divs = list_a;
	i = 0;
	while ((*list_divs) && (*list_divs)->divs == -1)
	{
		i++;
		*list_divs = (*list_divs)->next;
	}
	return (i);
}

void	null_number(t_number *number)
{
	number->a = 0;
	number->check_divs = 0;
	number->divs = 0;
	number->exit = 0;
	number->i = 0;
	number->inversion = 0;
	number->number_list = 0;
	number->rot = 0;
	number->sort_list_num = 0;
}

void	numbering(t_stack *list)
{
	t_stack	*max;
	t_stack	*min;

	min = scan_minmax(list, ALL, MIN);
	max = scan_minmax(list, ALL, MAX);
	while (min != max)
	{
		min->next_order = neighbour_list(min, ALL);
		if (min->next_order)
			min->next_order->back_order = min;
		min = min->next_order;
	}
}

t_stack	*scan_minmax(t_stack *list, int a, int minmax)
{
	t_stack	*min;
	t_stack	*dest;

	dest = list;
	min = list;
	if (dest && dest->back)
	{
		while (dest->back)
			dest = dest->back;
	}
	if (a != ALL)
	{
		while (dest && dest->next && dest->divs != a)
			dest = dest->next;
	}
	while (dest && (dest->divs == a || a == ALL))
	{
		if (minmax == MAX && min->count < dest->count)
			min = dest;
		if (minmax == MIN && min->count > dest->count)
			min = dest;
		dest = dest->next;
	}
	return (min);
}
