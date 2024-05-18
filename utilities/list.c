/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:12:49 by hbettal           #+#    #+#             */
/*   Updated: 2024/05/04 19:08:45 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst->env);
	free(lst);
	lst = NULL;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while ((*lst) != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		(*lst) = tmp;
	}
	free(*lst);
}

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->env = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*unit;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	unit = *lst;
	while (unit->next)
		unit = unit->next;
	unit->next = new;
}

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstdel_mid(t_list **data, t_list *rm)
{
	t_list *first = *data;
	if (rm)
	{
		while (first->next)
		{
			if (first->next == rm)
				break ;
			first = first->next;
		}
		if (rm->next)
			first->next = rm->next;
		else
			first->next = NULL;
	}
	ft_lstdelone(rm);
}