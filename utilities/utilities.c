/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:28:33 by hbettal           #+#    #+#             */
/*   Updated: 2024/05/31 05:19:35 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*where_path(t_list *data)
{
	t_list	*path;

	path = var_finder("PATH", &data);
	if (!path)
		return (NULL);
	return (path->env + 5);
}

