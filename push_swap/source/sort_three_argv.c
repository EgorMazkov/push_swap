/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:10:44 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 12:11:09 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_argv_min(t_stack **list_a)
{
	if ((*list_a)->count < (*list_a)->next->count && \
	(*list_a)->count > (*list_a)->next->next->count)
		list_rrab(list_a, 1);
	else if ((*list_a)->count < (*list_a)->next->count && \
	(*list_a)->count < (*list_a)->next->next->count && \
	(*list_a)->next->count > (*list_a)->next->next->count)
	{
		list_sasb(list_a, 1);
		list_rarb(list_a, 1);
	}
	else if ((*list_a)->count > (*list_a)->next->count && \
	(*list_a)->next->count > (*list_a)->next->next->count)
	{
		list_sasb(list_a, 1);
		list_rrab(list_a, 1);
	}
	sort_three_argv_min_case_two(list_a);
}

void	sort_three_argv_min_case_two(t_stack **list_a)
{
	if ((*list_a)->count > (*list_a)->next->count && \
	(*list_a)->next->count < (*list_a)->next->next->count && \
	(*list_a)->count > (*list_a)->next->next->count)
		list_rarb(list_a, 1);
	else if ((*list_a)->count > (*list_a)->next->count && \
	(*list_a)->next->count < (*list_a)->next->next->count && \
	(*list_a)->next->next->count > (*list_a)->count)
		list_sasb(list_a, 1);
	else if ((*list_a)->count < (*list_a)->next->count && \
	(*list_a)->next->count > (*list_a)->next->next->count)
		list_rrab(list_a, 1);
}

void	sort_three_argv_max(t_stack **list_a, t_stack **list_b)
{
	int		max;

	max = max_min_stack(*list_b);
	ft_check_max(list_a, list_b, max);
	sort_two_max(list_b);
}

void	sort_two_max(t_stack **list)
{
	if ((*list)->count < (*list)->next->count)
		list_sasb(list, 0);
}
