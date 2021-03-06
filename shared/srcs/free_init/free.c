/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:30:25 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 17:27:46 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "stack.h"

void	free_instructions(t_cmd **cmds)
{
	if (*cmds)
		free(*cmds);
	*cmds = NULL;
}

void	free_list(t_lst **list)
{
	t_lst	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	free_stack(t_stack **stack)
{
	if (!stack)
		return ;
	if (*stack)
	{
		if ((*stack)->head_a)
			free_list(&((*stack)->head_a));
		if ((*stack)->head_b)
			free_list(&((*stack)->head_b));
		(*stack)->head_a = NULL;
		(*stack)->tail_a = NULL;
		(*stack)->head_b = NULL;
		(*stack)->tail_b = NULL;
		free(*stack);
	}
	*stack = NULL;
}
