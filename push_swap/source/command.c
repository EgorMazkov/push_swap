/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:25:36 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 12:16:39 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	list_sasb(t_stack **lst, int a)
{
	t_stack	*two;
	t_stack	*one;

	if (!*lst)
		return ;
	while ((*lst)->back != NULL)
		(*lst) = (*lst)->back;
	if (!*lst || !(*lst)->next)
		return ;
	if (a == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	two = (*lst)->next;
	one = (*lst);
	*lst = (*lst)->next->next;
	two->next = one;
	two->back = NULL;
	one->back = two;
	one->next = (*lst);
	if (*lst)
		(*lst)->back = one;
	(*lst) = two;
}

void	list_rarb(t_stack **ab, int a)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!*ab || !(*ab)->next)
		return ;
	if (a == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	while ((*ab)->next)
		*ab = (*ab)->next;
	end = *ab;
	while ((*ab)->back)
		*ab = (*ab)->back;
	tmp = *ab;
	*ab = (*ab)->next;
	(*ab)->back = NULL;
	end->next = tmp;
	tmp->back = end;
	tmp->next = NULL;
}

void	list_pp(t_stack **a, t_stack **b, int s)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	if (s == 1)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
	while ((*a)->back)
		*a = (*a)->back;
	while (*b && (*b)->back)
		*b = (*b)->back;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->back = NULL;
	tmp->next = *b;
	if (*b)
		tmp->back = NULL;
	if (*b)
		(*b)->back = tmp;
	*b = tmp;
}

void	list_rrab(t_stack **lst, int a)
{
	t_stack	*tmp;

	if (a == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	tmp = *lst;
	(*lst) = (*lst)->back;
	(*lst)->next = NULL;
	tmp->back = NULL;
	while (*lst && (*lst)->back)
		*lst = (*lst)->back;
	tmp->next = *lst;
	(*lst) = ((*lst)->back = tmp);
}
