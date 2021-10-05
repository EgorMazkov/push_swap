/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumbert <ghumbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:38:19 by ghumbert          #+#    #+#             */
/*   Updated: 2021/09/13 15:42:24 by ghumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_perror(char *line, int i)
{
	(void)i;
	(void)line;
	write(1, "Error ", 7);
	write(1, "\n", 1);
	exit(0);
}

void	separation_stack(int argc, t_stack **list_a, t_stack **list_b)
{
	if (argc == 2)
		list_sasb(list_a, 1);
	else if (argc == 3)
		sort_three_argv_min(list_a);
	else if (argc == 4)
		sort_four_argv_min(list_a, list_b);
	else if (argc == 5)
		sort_five_list_mix(list_a, list_b);
	else if (argc > 5)
	{
		while (*list_a)
		{
			sort_list_for_divs(list_a, list_b, 1);
			while (numbert_fot_list(*list_b) > 1)
				sort_list_for_divs(list_b, list_a, 0);
			if (!*list_b)
				break ;
		}
		algoritm(list_a, list_b);
	}
}

int	main(int argc, const char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	t_mass	mass;
	int		i;
	int		flag;

	flag = 0;
	i = 1;
	mass.dest = NULL;
	list_b = NULL;
	mass.argc = argc - 1;
	mass.dest = handler_input(&argv[1], &mass.argc);
	flag = ft_check_sort(&mass);
	if (flag)
	{
		while (mass.argc)
			preim_pointers(&list_a, add_list(mass.dest[--mass.argc]));
	}
	else
		exit (0);
	numbering(list_a);
	separation_stack(numbert_fot_list(list_a), &list_a, &list_b);
	return (0);
}
