/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:13:17 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 12:15:39 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_fot_list_two(t_stack **list_a, t_stack **list_b, int num, int a)
{
	(void)list_b;
	if (num == 2)
	{
		if ((*list_a)->count < (*list_a)->next->count)
			list_sasb(list_a, a);
	}
}

t_stack	*add_list(int a)
{
	t_stack	*el;

	el = (t_stack *)malloc(sizeof(t_stack));
	if (!el)
		return (NULL);
	el->count = a;
	el->back = NULL;
	el->next_order = NULL;
	el->back_order = NULL;
	el->next = NULL;
	el->divs = 0;
	return (el);
}

t_stack	*ul_getmax_div(t_stack *lst)
{
	t_stack	*el_with_max_div;

	el_with_max_div = lst;
	while (lst->back)
		lst = lst->back;
	while (lst)
	{
		if (lst->divs > el_with_max_div->divs)
			el_with_max_div = lst;
		lst = lst->next;
	}
	return (el_with_max_div);
}
