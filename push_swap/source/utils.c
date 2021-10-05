/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:12:37 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 12:13:08 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	numbert_fot_list(t_stack *list)
{
	int	num;

	num = 0;
	while (list)
	{
		num++;
		list = list->next;
	}
	return (num);
}

int	scan_min_two(t_stack *list_a, int a)
{
	int	i;

	i = 0;
	if (list_a->divs == a)
	{
		while (list_a && list_a->divs == a)
		{
			i++;
			list_a = list_a->next;
		}
	}
	return (i);
}

t_stack	*scan_min(t_stack *list_a, int a, int min)
{
	t_stack	*mins;
	t_stack	*dest;
	int		i;

	i = 0;
	dest = list_a;
	mins = list_a;
	i = scan_min_two(list_a, a);
	while (dest && dest->back)
	{
		if (dest->back)
			dest = dest->back;
	}
	while (dest && dest->divs == a && min == MIN)
	{
		if (dest->count < mins->count)
			mins = dest;
		dest = dest->next;
	}
	return (mins);
}

t_stack	*get_mid(t_stack *list, int a)
{
	static int	count;
	int			len_for_el;
	t_stack		*min;
	t_stack		*max;

	max = scan_minmax(list, ALL, MAX);
	min = scan_min(list, a, MIN);
	len_for_el = len_for_element(list, a) / 2;
	while (list->count != min->count)
		list = list->next;
	while (list->next_order && len_for_el--)
		list = list->next_order;
	count = list->count;
	return (list);
}

int	len_for_element(t_stack *list, int a)
{
	int	i;

	i = 0;
	while (list->back)
		list = list->back;
	while (list)
	{
		if (list->divs == a || a == ALL)
			i++;
		list = list->next;
	}
	return (i);
}
