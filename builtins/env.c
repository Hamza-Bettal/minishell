/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:47:15 by hbettal           #+#    #+#             */
/*   Updated: 2024/04/23 17:20:05 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*fill_env(char **origin_env, t_list *data, t_minishell *mini)
{
	int		i;
	t_list	*tmp;
	char	*ctmp;

	i = -1;
	while (origin_env[++i])
		ft_lstadd_back(&data, ft_lstnew(origin_env[i]));
	tmp = data;
	ctmp = tmp->env;
	while (tmp->next)
	{
		ctmp = ft_strjoin_sp(ctmp, tmp->next->env);
		tmp = tmp->next;
		free(ctmp);
	}
	mini->new_env = ft_split(ctmp, ' ');
	return (data);
}

void	env_build(t_list *data, t_minishell *mini)
{
	if (ft_strncmp(data->env, "SECURITYSESSIONID", 17))
		data = data->next;
	if (data)
	{
		while (data)
		{
			printf("%s\n", data->env);
			data = data->next;
		}
	}
	else
	{
		if (mini->last_dir)
			printf("OLDPWD=%s\n", mini->last_dir);
		printf("PWD=%s\n", mini->curr_dir);
		printf("SHLVL=%d\n", mini->shlvl);
		// printf("_=%s", );
	}
}
