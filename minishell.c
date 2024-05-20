/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:02:41 by oelharbi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/19 19:18:52 by oelharbi         ###   ########.fr       */
=======
/*   Updated: 2024/05/18 15:27:30 by hbettal          ###   ########.fr       */
>>>>>>> 7a4cafab5450f5024d510a8b8b8b318734d9de93
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_init(t_minishell *mini)
{
	mini->input = NULL;
	mini->env_status = 0;
	mini->pids = NULL;
	mini->cmd = NULL;
	mini->table = NULL;
	mini->new_env = NULL;
	mini->trm_prompt = NULL;
	mini->last_dir = NULL;
	mini->curr_dir = getcwd(NULL, 0);
	mini->username = getenv("USER");
	mini->lst = NULL;
}

void	read_line(t_minishell *mini)
{
	mini->input = readline(mini->trm_prompt);
	if (mini->input)
		add_history(mini->input);
	else
	{
		printf("exit\n");
		exit(mini->exit_status);
	}
}

int	main(int ac, char **av, char **env)
{
	t_minishell	mini;

	(void)ac;
	(void)av;
	(void)env;
	mini_init(&mini);
	while (1)
	{
		signals(&mini.term);
		prompt_custom(&mini);
		read_line(&mini);
		lexer(&mini);
		parsing(&mini);
		ft_exit(&mini, NULL, NULL, 0);
	}
}