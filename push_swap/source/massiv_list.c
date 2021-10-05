/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massiv_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:26:59 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 14:44:08 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	lentab(char **mass)
{
	int	i;

	i = 0;
	while (mass[i])
		i++;
	return (i);
}

void	null_mass(t_mass *mass)
{
	mass->i = 0;
	mass->a = 0;
	mass->dest = 0;
	mass->flag = 0;
	mass->split = NULL;
	mass->argc = 0;
}

void	ft_mass(int argc, char **argv, t_mass *mass)
{
	int		i;

	null_mass(mass);
	i = 0;
	if (argc == 2)
	{
		mass->split = ft_split(argv[1], ' ');
		if (mass->split[i] == '\0')
			ft_perror("", 0);
		mass->dest = (int *)malloc(lentab(mass->split) * sizeof(int));
		if (!mass->dest)
			return ;
		mass->argc = lentab(mass->split);
		while (mass->split[mass->a] != NULL)
			mass->dest[mass->i++] = ft_atoi(mass->split[mass->a++]);
	}
	else
		ft_mass_two(argc, argv, mass);
}

void	ft_mass_two(int argc, char **argv, t_mass *mass)
{
	int	i;

	i = 1;
	mass->dest = (int *)malloc(sizeof(int) * (argc));
	if (!mass->dest)
		return ;
	mass->argc = --argc;
	while (argc > 0)
	{
		if (ft_atoll(argv[i]) > (int)(0x7FFFFFFF) || \
		ft_atoll(argv[i]) < -2147483648)
			ft_perror("", 0);
		else
			mass->dest[mass->i] = ft_atoll(argv[i]);
		mass->i++;
		argc--;
		i++;
	}
}

void	preim_pointers(t_stack **list, t_stack *element)
{
	if (!element)
		return ;
	if (!*list)
	{
		*list = element;
		return ;
	}
	element->next = *list;
	(*list)->back = element;
	*list = element;
}
